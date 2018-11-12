#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#define PORT 3307 
int main(int argc, char const *argv[]) 
{ 
    struct sockaddr_in serverAddress;
    struct sockaddr clientAddress;
    int sock, messageBytes; 
    socklen_t clientSize;
    char buffer[549] = {0};
    // Creating socket file descriptor 
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    }

    serverAddress.sin_family = AF_INET; 
    serverAddress.sin_addr.s_addr = INADDR_ANY; 
    serverAddress.sin_port = htons( PORT ); 

    if (bind(sock, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
 
    clientSize = sizeof(clientAddress); 
    while(true)
    {
        messageBytes = recvfrom(sock, buffer, 549, MSG_WAITALL, (struct sockaddr*) &clientAddress, &clientSize);
        buffer[messageBytes] = '\0';
        printf("%s\n",buffer ); 
    }
    return 0;
} 