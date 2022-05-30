#include <iostream>

#include "output_control.hpp"

void OutputControl::trips_list(std::vector<Trip*> trips)
{
    if(trips.size() == 0)
        throw std::runtime_error(EMPTY_ERROR);
        
    for(int i = 0; i < trips.size(); i++)
        if(!trips[i]->is_status(TRIP_DELETED))
            print_trip_data(trips[i]);
}

void OutputControl::trip_data(Trip* trip)
{
    if(trip->is_status(TRIP_DELETED))
        throw std::runtime_error(NOT_FOUND_ERROR);

   print_trip_data(trip);
}

void OutputControl::error(std::runtime_error& error) 
{
    std::cout << error.what() << std::endl;
}

void OutputControl::done()
{
    std::cout << DONE_PROMPT << std::endl;
}

void OutputControl::trip_id(int _id)
{
    std::cout << _id << std::endl;
}

void OutputControl::cost(double _cost)
{
    std::cout << _cost << std::endl;
}

void OutputControl::print_trip_data(Trip* trip)
{
    std::cout << trip->get_id() << TRIPS_DATA_DELIMITER <<
        trip->get_passenger()->get_username() << TRIPS_DATA_DELIMITER <<
        trip->get_origin()->get_name() << TRIPS_DATA_DELIMITER <<
        trip->get_destination()->get_name() << TRIPS_DATA_DELIMITER <<
        trip->get_price() << TRIPS_DATA_DELIMITER <<
        trip->get_status() <<
        std::endl;
}