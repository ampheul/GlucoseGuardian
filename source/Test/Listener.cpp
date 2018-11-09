#include <netinet/in.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SERVER_BUFFER_SIZE      1024

int main()
{
    int socketId = socket(PF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serverAddr;
    bzero((char*)&serverAddr, sizeof(serverAddr));
    serverAddr.sin_family       = AF_INET;
    serverAddr.sin_port         = htons(3307);
    serverAddr.sin_addr.s_addr  = INADDR_ANY;
    bind(socketId, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

    listen(socketId, 5);

    int                         finished    = 1;
    while(!finished)
    {
        struct  sockaddr_storage    serverStorage;
        socklen_t                   addr_size   = sizeof serverStorage;
        int newSocket = accept(socketId, (struct sockaddr*)&serverStorage, &addr_size);

        char        buffer[SERVER_BUFFER_SIZE];
        int         get = read(newSocket, buffer, SERVER_BUFFER_SIZE - 1);

        buffer[get] = '\0';
        fprintf(stdout, "%s\n", buffer);
    }
    close(socketId);
}