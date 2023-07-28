#include "IrcServer.hpp"

//EXTERN SIGNAL HANDLER
std::vector<int> clientSockets;

void signalHandler(int signal)
{
	std::cout << RED << "\n[IRC Server shutdown by SIGNAL]" << RESET << std::endl;
	std::cout << BLUE << "[Attempting graceful exit...]" << RESET << std::endl;
	for (size_t i = 0; i < clientSockets.size(); i++)
		close(clientSockets[i]);
	std::cout << BLUE << "[All connections closed]" << RESET << std::endl;
	std::cout << TITLE << CLEARLINE << "[Server shutdown successful]" << RESET << std::endl;
	exit(EXIT_SUCCESS);
	(void)signal;
}

//CLASS Utils
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

IrcServer::~IrcServer()
{
	std::cout << BLUE << "[Closing connections...]" << RESET << std::endl;
	for (size_t i = 0; i < clientSockets.size(); i++)
		close(clientSockets[i]);
	close(_serverFd);
	std::cout << BLUE << "[All connections closed]" << RESET << std::endl;
	std::cout << TITLE << CLEARLINE << "[Server shutdown successful]" << RESET << std::endl;
}



//METHODS
void IrcServer::run()
{
	std::cout << CLEAR << std::endl;
	std::cout << TITLE << CLEARLINE << " Ft_irc v4.2 - " << IPADDR << " - " << PORT << RESET << std::endl;
	std::cout << BLUE << "Waiting for connections..." << RESET << std::endl << std::endl;
	
	while (true)
	{
		int		dataSocketFd;
		int		dataAddrLen = sizeof(_serverSockAddr);
		char	socketData[MAX_DATA_SIZE] = {0};

		if ((dataSocketFd = accept(_serverFd, (struct sockaddr *)&_serverSockAddr, (socklen_t *)&dataAddrLen)) == -1)
		{
			throw AcceptException();
			exit(EXIT_FAILURE);
		}
		// std::string passwordsocketData(getpass("Password: "));
		// if (_serverPassword != passwordsocketData)
		// {
		// 	std::cout << "Invalid password. Closing connection." << std::endl;
		// 	close(dataSocketFd);
		// 	continue;
		// }
		clientSockets.push_back(dataSocketFd);
		if (read(dataSocketFd, socketData, sizeof(socketData) - 1) == 0)
		{
			std::cout << Utils::getLocalTime() << "Client disconnected." << std::endl;
			clientSockets.erase(std::remove(clientSockets.begin(), clientSockets.end(), dataSocketFd), clientSockets.end());
			close(dataSocketFd);
			continue ;
		}
		std::cout << Utils::getLocalTime() << "[" << socketData << "] received from client[" << dataSocketFd << "]." << std::endl;
		User test = User("gojo");
		test.addMessageToQueue("hi");
		test.addMessageToQueue("im");
		test.addMessageToQueue("gojo");
		test.setConnectedStatus(true);
		test.setNickname("kid gojo");
		test.setOperatorStatus(true);
		test.setUsername("op");

		_Channels.insert(std::make_pair("general", Channel("general", test)));
		_Channels["general"].addMode("khalass");
		_Channels["general"].setChannelTopic("haha");
		User test1 = test;
		User test2(test);
		_Channels["general"].addOperator(test2);
		_Channels["general"].setChannelPassword("guew");
	
		std::cout << test;
		test.removeMessageFromQueue("gojo");
		std::cout << test;
		// Utils::printMap(_Channels);
		// std::string hello = "Hello from IRCSERVER !";
		// write(dataSocketFd, hello.c_str(), hello.size() + 1);
	}
}
