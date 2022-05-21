#include <iostream>

#include "code/utaxi.hpp"

int main(int argc, char *argv[])
{
    Utaxi utaxi;
    utaxi.gather_loc_data(argv[1]);
    utaxi.run();
    return 0;
}