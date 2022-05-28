#include <iostream>
#include "output_control.hpp"

void OutputControl::trips_list(std::vector<Trip*> trips)
{
    if(trips.size() == 0)
        throw std::runtime_error("EMPTY");
    for(int i = 0; i < trips.size(); i++)
        if(!trips[i]->is_status(TRIP_DELETED))
        {
            std::cout << trips[i]->get_id() << TRIPS_DATA_DELIMITER <<
            trips[i]->get_passenger()->get_username() << TRIPS_DATA_DELIMITER <<
                trips[i]->get_origin()->get_name() << TRIPS_DATA_DELIMITER <<
                    trips[i]->get_destination()->get_name() << TRIPS_DATA_DELIMITER <<
                        trips[i]->get_status() <<
                            std::endl;
        }   
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

void OutputControl::trip_data(Trip* trip)
{
    if(trip->is_status(TRIP_DELETED))
        throw std::runtime_error("Not Found");

    std::cout << trip->get_id() << TRIPS_DATA_DELIMITER <<
        trip->get_passenger()->get_username() << TRIPS_DATA_DELIMITER <<
            trip->get_origin()->get_name() << TRIPS_DATA_DELIMITER <<
                trip->get_destination()->get_name() << TRIPS_DATA_DELIMITER <<
                    trip->get_status() <<
                        std::endl;
}