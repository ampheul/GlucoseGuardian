/*
	Laptop connection implementation
	author: Graeme Brabers
*/

#include "LaptopOutput.h"

bool LaptopOutput::connectToPump(const std::string address, const int port)
{
	//establish socket
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		std::cout << "Socket creation error" << std::endl;
		return false;
	}
	else
	{
		std::cout << "Socket created" << std::endl;
		return true;
	}

	//clear memory for connection
	memset(&server, '0', sizeof(server));
	
	//server settings
	server.sin_family = AF_INET;
	server.sin_port = htons(port);
	server.sin_addr.s_addr = inet_addr(address.c_str());

	//connect to socket
	if ((connectionStatus = connect(sock, (struct sockaddr *)&server, sizeof(server))) < 0)
	{
		std::cout << "Error connecting to socket" << std::endl;
		close(sock);
	}
	else
	{
		std::cout << "Connection established" << std::endl;
	}
}

//default constructor - not used
LaptopOutput::LaptopOutput()
{
}

//overloaded constructor - force connection
LaptopOutput::LaptopOutput(const std::string hostname, const int port)
{
	LaptopOutput::connectToPump(hostname, port);
}

//destructor
LaptopOutput::~LaptopOutput()
{
	close(sock);
}

//transmit message
void LaptopOutput::sendInstruction(const HormoneDose * hormone) const
{
	if (sock == -1)
	{
		std::cout << "Error: socket not established" << std::endl;
	}
	else if (connectionStatus == -1)
	{
		std::cout << "Error: connection not established" << std::endl;
	}
	else
	{
		switch (hormone->getHormoneType())
		{
		case BASAL_INSULIN:
			type = "BASAL_INSULIN";
			break;
		case BOLUS_INSULIN:
			type = "BOLUS_INSULIN";
			break;
		case GLUCAGON:
			type = "GLUCAGON";
			break;
		}

		message << type << "," << amount;
		strMessage = message.str();
		charArrayMessage = strMessage.c_str();
		send(sock, charArrayMessage, strlen(charArrayMessage), 0);
	}
}
