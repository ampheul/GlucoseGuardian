#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#define PORT 3307 
int main(int argc, char const *argv[]) 
{ 
    int server_fd, len, messageBytes; 
    struct sockaddr_in address, clientAddress; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char buffer[549] = {0}; 
       
    // Creating socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_DGRAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    }

    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 

    // Forcefully attaching socket to the port 8080 
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
 
    while(true)
    {
        messageBytes = recvfrom(server_fd, buffer, 549, MSG_WAITALL, (struct sockaddr_in *)clientAddress, &len);
        buffer[messageBytes] = '\0';
        printf("%s\n",buffer ); 
    }
    return 0;
} 