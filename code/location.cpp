#include "location.hpp"

Location::Location()
{
    ;
}

Location::Location(std::string _name, double _lat, double _long)
{
    name = _name;
    latitude = _lat;
    longitude = _long;
}

bool Location::is_same_as(std::string check_loc)
{
    return (name == check_loc);
}