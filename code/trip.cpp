#include "trip.hpp"

Trip::Trip(std::string _passenger_name, Location _origin, Location _destination)
{
    passenger_name = _passenger_name;
    origin = _origin;
    destination = _destination;
    status = TRIP_WAITING;
}