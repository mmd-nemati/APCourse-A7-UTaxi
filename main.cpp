#include "code/utaxi.hpp"
#include <iostream>
#include <iomanip> 
int main(int argc, char *argv[])
{
    std::cout << std::fixed << std::setprecision(2);
    //std::cout << std::setprecision(2);
    Utaxi utaxi;
    utaxi.gather_loc_data(argv[1]);
    utaxi.run();

    return 0;
}