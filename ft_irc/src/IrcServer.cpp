#include "IrcServer.hpp"

std::vector<int> clientSockets;

void signalHandler(int signal)
{
	std::cout << RED_ANSI << "\n[IRC Server shutdown by SIGNAL]" << END_ANSI << std::endl;
	std::cout << BLU_ANSI << "[Attempting graceful exit...]" << END_ANSI << std::endl;
	for (size_t i = 0; i < clientSockets.size(); i++)
		close(clientSockets[i]);
	std::cout << TITLE << "[Client connections closed]" << END_ANSI << std::endl;
	exit(EXIT_SUCCESS);
	(void)signal;
}

IrcServer::IrcServer()
{}

IrcServer::IrcServer(const std::string &portNumber) : _port(0), server_fd(-1)
{
	//DEFINE SIGHANDLERS
	std::signal(SIGINT, signalHandler);
	std::signal(SIGQUIT, signalHandler);
	try
	{
		//PARSING PORT
		_port = atoi(portNumber.c_str());
		if ((_port == 0 && portNumber != "0") || _port < 0)
			throw InvalidPortException();
		if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
			throw SocketCreationException();
		//NAMING SOCKET
		sock_addr.sin_family = AF_INET;
		sock_addr.sin_addr.s_addr = INADDR_ANY;
		sock_addr.sin_port = htons(_port);
		std::memset(sock_addr.sin_zero, 0, sizeof(sock_addr.sin_zero));
		if (bind(server_fd, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) == -1)
		{
			close(server_fd);
			throw BindException();
		}
		//LISTEN
		if (listen(server_fd, QUEUE_BACKLOG) == -1)
			throw ListenException();
	} catch (const InvalidPortException& err) {
		std::cerr << err.what() << std::endl;
		exit(EXIT_FAILURE);
	} catch (const SocketCreationException& err) {
		std::cerr << err.what() << std::endl;
		exit(EXIT_FAILURE);
	} catch (const BindException& err) {
		std::cerr << err.what() << std::endl;
		exit(EXIT_FAILURE);
	} catch (const ListenException& err) {
		std::cerr << err.what() << std::endl;
		exit(EXIT_FAILURE);
	}
}

IrcServer::~IrcServer()
{
	std::cout << BLU_ANSI << "[Closing connections...]" << END_ANSI << std::endl;
	for (size_t i = 0; i < clientSockets.size(); i++)
		close(clientSockets[i]);
	close(server_fd);
	std::cout << TITLE << "[All connections closed]" << END_ANSI << std::endl;
}

void IrcServer::run()
{
	std::cout << TITLE << "IRCSERVER IS ONLINE" << END_ANSI << std::endl;
	std::cout << BLU_ANSI << "Waiting for connections..." << END_ANSI << std::endl << std::endl;
	while (true)
	{
		int new_socket;
		int addrlen = sizeof(sock_addr);
		if ((new_socket = accept(server_fd, (struct sockaddr *)&sock_addr, (socklen_t *)&addrlen)) == -1) {
			std::perror("In accept");
			exit(EXIT_FAILURE);
		}

		// Add the new client socket to the container
		clientSockets.push_back(new_socket);

		char buffer[30000] = {0};
		long valread = read(new_socket, buffer, sizeof(buffer) - 1);

		// Check for EOF (Ctrl+D)
		if (valread == 0) {
			std::cout << "Client disconnected." << std::endl;
			// Remove the disconnected client socket from the container
			clientSockets.erase(std::remove(clientSockets.begin(), clientSockets.end(), new_socket), clientSockets.end());
			close(new_socket);
			continue;
		}

		std::string hello = "Hello from IRCSERVER !";
		write(new_socket, hello.c_str(), hello.size() + 1);
		std::cout << "Message : [" << buffer << "] received from client[" << new_socket << "]." << std::endl;
	}
}
