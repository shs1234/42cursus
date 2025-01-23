#include "Server.hpp"

int main(int ac, char **av)
{
    try
    {
        Server server(ac, av);
        server.run();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
