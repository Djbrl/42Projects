#include "IrcServer.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	IrcServer server(av[1]);

	server.run();
}
