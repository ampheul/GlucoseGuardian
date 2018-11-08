#include "LaptopOutput.h"

bool LaptopOutput::connectToPump(const std::string address, const int port)
{
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

	memset(&server, '0', sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(port);
	server.sin_addr.s_addr = inet_addr(address.c_str);

	
	if ((connectionStatus = connect(sock, (struct sockaddr *)&server, sizeof(server))) < 0)
	{
		std::cout << "Error connecting to pump" << std::endl;
		close(sock);
	}
}

LaptopOutput::LaptopOutput()
{
}

LaptopOutput::LaptopOutput(const std::string ip, const int prt)
{
	LaptopOutput::connectToPump(ip, prt);
}

LaptopOutput::~LaptopOutput()
{
	close(sock);
}

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
		case 0:
			type = "Basal Insulin";
			break;
		case 1:
			type = "Bolus Insulin";
			break;
		case 2:
			type = "Glucagon";
			break;
		}

		message << type << "," << amount;
		charArrayMessage = message.str().c_str;
		send(sock, charArrayMessage, strlen(charArrayMessage), 0);
	}
}
