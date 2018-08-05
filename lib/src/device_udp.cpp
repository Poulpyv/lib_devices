#include "device_udp.h"
#include <iostream>

using namespace Devices;

RetCode CDevice_UDP_Client::connect(){
    return RET_OK;
}

RetCode CDevice_UDP_Client::read(std::string& data, uint32_t size){
    char* buffer = new char[size];
    unsigned int size_sockaddr = sizeof(struct sockaddr);
    recvfrom(m_socket_info, buffer, size, 0, reinterpret_cast<sockaddr*>(&m_socket), &size_sockaddr);
    data.assign(buffer);
    delete[] buffer;
    return RET_OK;
}

RetCode CDevice_UDP_Client::write(const std::string& data){
    sendto(m_socket_info, data.data(), data.size(), MSG_CONFIRM, reinterpret_cast<sockaddr*>(&m_socket), sizeof(m_socket));
    return RET_OK;
}

RetCode CDevice_UDP_Server::connect(){
    return RET_OK;
}

RetCode CDevice_UDP_Server::read(std::string& data, uint32_t size){
    char* buffer = new char[size];
    unsigned int size_sockaddr = sizeof(struct sockaddr);
    recvfrom(m_socket_info, buffer, size, 0, reinterpret_cast<sockaddr*>(&m_socket), &size_sockaddr);
    data.assign(buffer);
    delete[] buffer;
    return RET_OK;
}

RetCode CDevice_UDP_Server::write(const std::string& data){
    sendto(m_socket_info, data.data(), data.size(), MSG_CONFIRM, reinterpret_cast<sockaddr*>(&m_socket), sizeof(m_socket));
    return RET_OK;
}

