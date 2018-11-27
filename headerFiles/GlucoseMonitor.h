#ifndef GLUCOSEMONITOR_H
#define GLUCOSEMONITOR_H

#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <mutex>
#include <netinet/in.h>
#include "ArtificialPancreas.h"

#define PORT 3306

class GlucoseMonitor
{
    private:
        struct sockaddr_in serverAddress;
        int sock;
        socklen_t clientSize;
        char buffer[549] = {0};
        std::string input;
    public:
		GlucoseMonitor();
		~GlucoseMonitor();
        void setup();
        void listen(const ArtificialPancreas *);
};

#endif
