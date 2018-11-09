/*
	Laptop connection header file
	author: Graeme Brabers
*/

#include <string>
#include <iostream>
#include <sstream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "HormoneDose.h"

class LaptopOutput
{
private:
	int sock, connectionStatus;
	struct sockaddr_in server;
	socklen_t serverSize;
	bool connectToPump(const std::string, const int);
	std::string type, amount;
	std::stringstream message;
	char* charArrayMessage;
	LaptopOutput();
public:
	LaptopOutput(const std::string, const int);
	~LaptopOutput();
	void sendInstruction(const HormoneDose *);
};
