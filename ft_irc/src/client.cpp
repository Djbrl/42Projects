#include "IrcServer.hpp"
#include <arpa/inet.h>
#include <sys/cdefs.h>

typedef struct sockaddr_in socket_addr;

int main(int argc, char const *argv[])
{
    long        valread;
    int         sock = 0; 
    char        buffer[1024] = {0};
    socket_addr serv_addr;

	// Creating socket file descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

	//Fill sock addr
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

	//Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

	//Send Data
    std::string hello = "Hello from client !";
    send(sock , hello.c_str() , hello.size() , 0 );
    //Read Data
	valread = read( sock , buffer, 1024);
    printf("[IRCServer] : %s\n",buffer );
	close(sock);
    return 0;
}