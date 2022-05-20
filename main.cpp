#include <iostream>

#include "utaxi/utaxi.hpp"

int main(int argc, char *argv[])
{
    Utaxi utaxi;
    utaxi.gather_loc_data(argv[1]);

    return 0;
}