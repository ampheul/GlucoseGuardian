#include "GlucoseMontor.h"

void GlucoseMonitor::setup()
{
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(PORT);

    //bind to socket
    if (bind(sock, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
}

void GlucoseMonitor::listen(const ArtificialPancreas * pancreas)
{
    while(true)
    {
        recv(sock, buffer, 549, 0);
        input.str(std::string(buffer));
        
        memset(buffer, 0, sizeof(buffer));
        input.clear();
    }
}