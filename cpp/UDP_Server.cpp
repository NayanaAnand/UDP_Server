#include "UDP_Server.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT    4045
#define MAXLINE 1024

#define SA struct sockaddr

PREPARE_LOGGING(UDP_Server_i)

UDP_Server_i::UDP_Server_i(const char *uuid, const char *label) :
    UDP_Server_base(uuid, label)
{
    // Avoid placing constructor code here. Instead, use the "constructor" function.

}

UDP_Server_i::~UDP_Server_i()
{
}

void UDP_Server_i::constructor()
{
    /***********************************************************************************
     This is the RH constructor. All properties are properly initialized before this function is called 
    ***********************************************************************************/
}

int UDP_Server_i::serviceFunction()
{
	int sockfd;
        char buffer[MAXLINE];
        char *buff;
        char *hello = "Hello from server";
        struct sockaddr_in servaddr, cliaddr;
        if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
                perror("socket creation failed");
                exit(EXIT_FAILURE);
        }
        else
                LOG_INFO(UDP_Server_i, "Socket created successfully");
        memset(&servaddr, 0, sizeof(servaddr));
        memset(&cliaddr, 0, sizeof(cliaddr));
        servaddr.sin_family = AF_INET; // IPv4
        servaddr.sin_addr.s_addr = INADDR_ANY;
        servaddr.sin_port = htons(PORT);
        if ( bind(sockfd, (const struct sockaddr *)&servaddr,
                        sizeof(servaddr)) < 0 )
        {
                perror("bind failed");
                exit(EXIT_FAILURE);
        }
        else
                LOG_INFO(UDP_Server_i, "Bind is completed");
        int len, n;
        len = sizeof(cliaddr);
        n = recvfrom(sockfd, (char *)buff, MAXLINE, MSG_WAITALL, ( struct sockaddr *) &cliaddr, (socklen_t*)&len);
        LOG_INFO(UDP_Server_i, "Data Recieved : " << buff);
        buffer[n] = '\0';
        sendto(sockfd, (const char *)hello, strlen(hello), MSG_CONFIRM, (const struct sockaddr *) &cliaddr, len);
        LOG_INFO(UDP_Server_i, "Hello message sent");
	return 0;

}
