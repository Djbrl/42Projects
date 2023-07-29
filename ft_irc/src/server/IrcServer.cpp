#include "IrcServer.hpp"

//EXTERN SIGNAL HANDLER__________________________________________________________________________________________________________________________
//Header-level client socket lists
std::vector<int> g_clientSockets;

//Signal handler for SIGINT and SIGQUIT to avoid port-clogging on abrupt exit
void signalHandler(int signal)
{
	std::cout << YELLOW << "\n[IRC Server shutdown by SIGNAL, attempting graceful exit...]" << RESET << std::endl;
	for (size_t i = 0; i < g_clientSockets.size(); i++)
		close(g_clientSockets[i]);
	std::cout << TITLE << CLEARLINE << "[Server shutdown successful]" << RESET << std::endl;
	exit(EXIT_SUCCESS);
	(void)signal;
}

//IRCSERVER CLASS______________________________________________________________________________________________________________________________________
//IrcServer can't be instantiated using the default constructor
IrcServer::IrcServer()
{}

//Mandatory constructor, protected with try-catches
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
		//LISTEN PORT WITH BACKLOG ENABLED
		if (listen(_serverFd, QUEUE_BACKLOG) == -1)
			throw ListenException();
		g_clientSockets.push_back(_serverFd);
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

//IrcServer destructor close all the client sockets and the server socket
IrcServer::~IrcServer()
{
	for (size_t i = 0; i < g_clientSockets.size(); i++)
		close(g_clientSockets[i]);
	std::cout << TITLE << CLEARLINE << "[Server shutdown successful]" << RESET << std::endl;
}

IrcServer::IrcServer(const IrcServer &cpy)
{
	if (this != &cpy)
		*this = cpy;
}

IrcServer &IrcServer::operator=(const IrcServer &cpy)
{
	if (this != &cpy)
	{
		_serverSockAddr = cpy._serverSockAddr;
		_serverPort = cpy._serverPort;
		_serverPassword = cpy._serverPassword;
		_serverFd = cpy._serverFd;
		_ConnectedUsers = cpy._ConnectedUsers;
		_Channels = cpy._Channels;
	}
	return *this;
}

void IrcServer::run()
{
    // Title bar
    std::cout << CLEAR << std::endl;
    std::cout << TITLE << CLEARLINE << " Ft_irc v4.2 - " << IPADDR << " - " << PORT << RESET << std::endl;
    std::cout << BLUE << "Waiting for connections..." << RESET << std::endl << std::endl;

    while (true)
    {
        int dataSocketFd = acceptClient();
        readData(dataSocketFd);
        displayClientInfo(dataSocketFd);
    }
}

