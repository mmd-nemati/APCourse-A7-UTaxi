#include <iostream>
#include "output_control.hpp"

void OutputControl::trips_list(std::vector<Trip*> trips)
{
    for(int i = 0; i < trips.size(); i++)
        std::cout << trips[i]->get_id() << TRIPS_DATA_DELIMITER <<
            trips[i]->get_passenger()->get_username() << TRIPS_DATA_DELIMITER <<
                trips[i]->get_origin()->get_name() << TRIPS_DATA_DELIMITER <<
                    trips[i]->get_destination()->get_name() << TRIPS_DATA_DELIMITER <<
                        std::endl;
}

void OutputControl::error(std::runtime_error& error) 
{
    std::cout << error.what() << std::endl;
}

void OutputControl::done()
{
    std::cout << "OK" << std::endl;
}

void OutputControl::trip_id(int _id)
{
    std::cout << _id << std::endl;
}