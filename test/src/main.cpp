#include "device_udp.h"
#include <iostream>
#include <string>

int main()
{
	std::cout << "Testing devices lib...\n";
	CDevice_UDP_Server dev1("127.0.0.1", 4321);
	CDevice_UDP_Client dev2("127.0.0.1", 4321);

	std::string msg_s = "hello world";
	std::cout << "CDevice_UDP_Client :: sending :: '" << msg_s << "'" << std::endl;
	dev2.write(msg_s);

	std::string msg_r;
	dev1.read(msg_r);
	std::cout << "CDevice_UDP_Server :: received :: '" << msg_r << "'" << std::endl;

	if( msg_s != msg_r )
	{
		std::cout << "CDevice_UDP :: error :: message received not the same as message sent" << std::endl;
	}
	else
	{
		std::cout << "CDevice_UDP :: success :: message received the same as message sent" << std::endl;
	}

	return 0;
}