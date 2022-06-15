#include "server/server.hpp"
#include "code/interface.hpp"
#include <iostream>
#include <iomanip> 

int main(int argc, char *argv[])
{
    std::cout << std::fixed << std::setprecision(2);
    Interface interface;
    std::cout << "----------------" << std::endl;
    interface.run(argv);


    return 0;
}