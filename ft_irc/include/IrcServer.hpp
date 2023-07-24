#ifndef __IRC_SERVER_HPP__
# define __IRC_SERVER_HPP__

# include "AServer.hpp"

class IrcServer : public AServer
{
	private:
	sockaddr_in_t					_serverSockAddr;
	unsigned int					_serverPort;
	std::string						_serverPassword;
	int								_serverFd;
									IrcServer();
	public:
									~IrcServer();
									IrcServer(const std::string& portNumber, const std::string& password);
									IrcServer(const IrcServer &cpy);
	IrcServer						&operator=(const IrcServer &cpy);
	std::string						getServerTime();
	void							run();
};

#endif
