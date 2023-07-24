#include "IrcServer.hpp"

int main(int ac, char **av)
{
	if (ac != 3)
		return 1;
	IrcServer server(av[1], av[2]);

	server.run();
}
