#include "trip.hpp"

Trip::Trip(Member* _passenger, Location* _origin, Location* _destination, int _id)
{
    passenger = _passenger;
    origin = _origin;
    destination = _destination;
    status = TRIP_WAITING;
    trip_id = _id;
}