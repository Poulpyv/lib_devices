#pragma once
#include "devices.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
using namespace Devices;

class CDevice_UDP_Client : public CDevice{
public:
    CDevice_UDP_Client(const std::string& ip_addr, uint32_t port)
    {
		m_socket_info = socket(AF_INET, SOCK_DGRAM, 0);
		if (m_socket_info == -1) {
			printf("Could not create socket");
		}
		m_socket.sin_addr.s_addr = inet_addr(ip_addr.c_str());
		m_socket.sin_family = AF_INET;
		m_socket.sin_port = htons(port);
    }

    virtual ~CDevice_UDP_Client() {};

    virtual RetCode connect() final;
    virtual RetCode read(std::string&, uint32_t size = 1024) final;
    virtual RetCode write(const std::string&) final;
private:
	int m_socket_info;
    struct sockaddr_in m_socket;
};

class CDevice_UDP_Server : public CDevice{
public:
    CDevice_UDP_Server(const std::string& ip_addr, uint32_t port)
    {
		m_socket_info = socket(AF_INET, SOCK_DGRAM, 0);
		if (m_socket_info == -1) {
			printf("Could not create socket");
		}
		m_socket.sin_addr.s_addr = INADDR_ANY;
		m_socket.sin_family = AF_INET;
		m_socket.sin_port = htons(port);
		bind(m_socket_info, (const struct sockaddr *)&m_socket, sizeof(m_socket));
    }

    virtual ~CDevice_UDP_Server() {};

    virtual RetCode connect() final;
    virtual RetCode read(std::string&, uint32_t size = 1024) final;
    virtual RetCode write(const std::string&) final;
private:
	int m_socket_info;
    struct sockaddr_in m_socket;
};
