#include "InsulinPump.h"

InsulinPump::InsulinPump()
{
	if ((sock = socket(PF_INET, SOCK_STREAM, 0)) < 0)
	{
		std::cout << "Error establishing socket" << std::endl;
	}

	addressSize = sizeof(address);
	bzero(&address, addressSize);
	address.sin_family = AF_INET;
	address.sin_port = htons(3307);
	address.sin_addr.s_addr = INADDR_ANY;
	
	if (bind(sock, (struct sockaddr *)&address, addressSize) == -1)
	{
		std::cout << "Failed to bind" << std::endl;
		close(sock);    // Don't forget to close the socket.
	}
	else
	{
		listen(sock, 5);

		while (true)
		{
			incomming = read(sock, buffer, 1024);
			std::cout << buffer << std::endl;
		}
	}
}


InsulinPump::~InsulinPump()
{
}
