#include "IrcServer.hpp"

int IrcServer::acceptClient()
{
    int dataSocketFd;
    int dataAddrLen = sizeof(_serverSockAddr);

    if ((dataSocketFd = accept(_serverFd, (struct sockaddr *)&_serverSockAddr, (socklen_t *)&dataAddrLen)) == -1)
    {
        throw AcceptException();
        exit(EXIT_FAILURE);
    }

    g_clientSockets.push_back(dataSocketFd);
    return dataSocketFd;
}

void IrcServer::readData(int clientSocket)
{
    char socketData[MAX_DATA_SIZE] = {0};
    if (read(clientSocket, socketData, sizeof(socketData) - 1) == 0)
    {
        std::cout << Utils::getLocalTime() << "Client disconnected." << std::endl;
        g_clientSockets.erase(std::remove(g_clientSockets.begin(), g_clientSockets.end(), clientSocket), g_clientSockets.end());
        close(clientSocket);
        return;
    }

    std::istringstream iss(socketData);
    std::string command;
    iss >> command;

    processCommand(command, clientSocket);
}

void IrcServer::displayClientInfo(int clientSocket)
{
    char socketData[MAX_DATA_SIZE] = {0}; // Declare and initialize socketData
    if (read(clientSocket, socketData, sizeof(socketData) - 1) == 0)
    {
        std::cout << Utils::getLocalTime() << "Client disconnected." << std::endl;
        g_clientSockets.erase(std::remove(g_clientSockets.begin(), g_clientSockets.end(), clientSocket), g_clientSockets.end());
        close(clientSocket);
        return;
    }

    char clientIP[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(_serverSockAddr.sin_addr), clientIP, INET_ADDRSTRLEN);
    std::cout << Utils::getLocalTime() << "[" << socketData << "] received from client[" << clientSocket << "] " << BYELLOW << clientIP << RESET << "." << std::endl;
}

void IrcServer::processCommand(const std::string& command, int clientSocket)
{
    if (command == "NICK") {
        std::string password;
        read(clientSocket, &password[0], password.size());
        std::string response = "NICK command received and processed.";
        write(clientSocket, response.c_str(), response.size());
    }
}
