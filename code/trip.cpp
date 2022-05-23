#include "trip.hpp"

Trip::Trip(Member* _passenger, Location* _origin, Location* _destination, int _id)
{
    passenger = _passenger;
    origin = _origin;
    destination = _destination;
    status = TRIP_WAITING;
    trip_id = _id;
}

bool Trip::is_same_as(int _id)
{
    return (trip_id == _id);
}

void Trip::start()
{
    status = TRIP_TRAVELING;
}

void Trip::finish()
{
    status = TRIP_FINISHED;
}