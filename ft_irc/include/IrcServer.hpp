#ifndef __IRC_SERVER_HPP__
# define __IRC_SERVER_HPP__

# include <iostream>
# include <sys/socket.h>
# include <netinet/in.h>
# include <unistd.h>
# include <csignal>
# include <vector>

# define TITLE "\033[44;97m"
# define BLU_ANSI "\033[0;34m"
# define YLW_ANSI "\033[0;33m"
# define GREEN_ANSI "\033[0;32m"
# define RED_ANSI "\033[0;31m"
# define END_ANSI "\033[0m"
# define PORT 8080
# define QUEUE_BACKLOG 10

typedef struct sockaddr_in	sockaddr_in_t;
extern std::vector<int>		clientSockets;
void						signalHandler(int signal);

class IrcServer
{
	private:
		unsigned int				_port;
		sockaddr_in_t				sock_addr;
		int							server_fd;
		IrcServer();

	public:
    	IrcServer(const std::string& portNumber);
		~IrcServer();
		IrcServer(const IrcServer &cpy);
		IrcServer &operator=(const IrcServer &cpy);
		void run();
	
		class InvalidPortException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Exception: Invalid or occupied port number provided.";
			}
		};

		class SocketCreationException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Exception: Socket creation failed.";
			}
		};

		class BindException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Exception: Bind() failed.";
			}
		};

		class ListenException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Exception: Listen() failed.";
			}
		};

		class AcceptException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Exception: Accept() failed.";
			}
		};
};

#endif
