#ifndef __DEFINES_HPP__
# define __DEFINES_HPP__

//LIBRAIRES CLASS____________________________________________________________________________________________________

# include <iostream>
# include <sys/socket.h>
# include <netinet/in.h>
# include <unistd.h>
# include <csignal>
# include <ctime>
# include <vector>
# include <map>
# include <sstream>

//ANSI CODES_________________________________________________________________________________________________________

# define CLEARLINE "\033[2K"
# define CLEAR "\033[2J\033[H"
# define TITLE "\033[44;97m"
# define BWHITE "\033[1;37m"
# define BLUE "\033[0;34m"
# define YELLOW "\033[0;33m"
# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define RESET "\033[0m"

//DEFINES____________________________________________________________________________________________________________

# define QUEUE_BACKLOG 10
# define IPADDR "127.0.0.1"
# define PORT 8080
# define MAX_DATA_SIZE 4096

//GLOBAL_____________________________________________________________________________________________________________

typedef struct sockaddr_in	sockaddr_in_t;
extern std::vector<int>		clientSockets;
void						signalHandler(int signal);

#endif
