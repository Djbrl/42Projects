#include "IrcServer.hpp"

std::vector<int> clientSockets;

void signalHandler(int signal)
{
	std::cout << RED << "\n[IRC Server shutdown by SIGNAL]" << RESET << std::endl;
	std::cout << BLUE << "[Attempting graceful exit...]" << RESET << std::endl;
	for (size_t i = 0; i < clientSockets.size(); i++)
		close(clientSockets[i]);
	std::cout << TITLE << CLEARLINE << "[Client connections closed]" << RESET << std::endl;
	exit(EXIT_SUCCESS);
	(void)signal;
}

IrcServer::IrcServer()
{}

IrcServer::IrcServer(const std::string &portNumber, const std::string& password) : _serverPort(0),  _serverPassword(password), _serverFd(-1)
{
	//DEFINE SIGHANDLERS
	std::signal(SIGINT, signalHandler);
	std::signal(SIGQUIT, signalHandler);
	try
	{
		//PARSING PORT
		_serverPort = atoi(portNumber.c_str());
		if ((_serverPort == 0 && portNumber != "0") || _serverPort < 0)
			throw InvalidPortException();
		if ((_serverFd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
			throw SocketCreationException();
		//NAMING SOCKET
		_serverSockAddr.sin_family = AF_INET;
		_serverSockAddr.sin_addr.s_addr = INADDR_ANY;
		_serverSockAddr.sin_port = htons(_serverPort);
		std::memset(_serverSockAddr.sin_zero, 0, sizeof(_serverSockAddr.sin_zero));
		if (bind(_serverFd, (struct sockaddr *)&_serverSockAddr, sizeof(_serverSockAddr)) == -1)
		{
			close(_serverFd);
			throw BindException();
		}
		//LISTEN
		if (listen(_serverFd, QUEUE_BACKLOG) == -1)
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
	std::cout << BLUE << "[Closing connections...]" << RESET << std::endl;
	for (size_t i = 0; i < clientSockets.size(); i++)
		close(clientSockets[i]);
	close(_serverFd);
	std::cout << TITLE << CLEARLINE << "[All connections closed]" << RESET << std::endl;
}

std::string IrcServer::getServerTime()
{
    time_t rawTime;
    time(&rawTime);
    struct tm *timeInfo = localtime(&rawTime);

    // Format the local timestamp as a string
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%c", timeInfo);

    // Extract hours and minutes from the time string
    std::string time = buffer;
    std::string hours = time.substr(11, 2);
    std::string minutes = time.substr(14, 2);

    // Combine the hour and minute fields into a single string
    std::string localTime = BWHITE + hours + ":" + minutes + " -:- " + RESET ;

    return localTime;
}

void IrcServer::run()
{
	// std::cout << CLEAR << std::endl;
	std::cout << TITLE << CLEARLINE << " Ft_irc v4.2 - " << IPADDR << " - " << PORT << RESET << std::endl;
	std::cout << BLUE << "Waiting for connections..." << RESET << std::endl << std::endl;
	
	while (true)
	{
		int new_socket;
		int addrlen = sizeof(_serverSockAddr);
		if ((new_socket = accept(_serverFd, (struct sockaddr *)&_serverSockAddr, (socklen_t *)&addrlen)) == -1) {
			std::perror("In accept");
			exit(EXIT_FAILURE);
		}

		std::string passwordBuffer(getpass("Password: "));

		// Check if the password matches
		if (_serverPassword != passwordBuffer)
		{
			std::cout << "Invalid password. Closing connection." << std::endl;
			close(new_socket);
			continue;
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
		std::cout << getServerTime() << "Message : \n[" << buffer << "] received from client[" << new_socket << "]." << std::endl;
	}
}
