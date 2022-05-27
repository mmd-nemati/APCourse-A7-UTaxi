#include "location.hpp"

Location::Location()
{
    ;
}

Location::Location(std::string _name, double _lat, double _long, int _traffic)
{
    name = _name;
    latitude = _lat;
    longitude = _long;
    traffic = _traffic;
}

bool Location::is_same_as(std::string check_loc)
{
    return (name == check_loc);
}

double Location::calc_distance(Location* loc2)
{
    double dist = 0;
    dist = LENGTH_OF_A_DEGREE * calc_linear_dist(this->latitude, this->longitude, loc2->latitude, loc2->longitude);

    return dist;
}

int Location::calc_traffic_factor(Location* loc2)
{
    return (this->traffic + loc2->traffic);
}