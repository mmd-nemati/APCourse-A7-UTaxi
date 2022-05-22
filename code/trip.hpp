#ifndef __TRIP_H__
#define __TRIP_H__

#include <string>
#include "location.hpp"
#include "../defines.hpp"

class Trip
{
    public:
        Trip() {};
        Trip(std::string _passenger_name, Location _origin, Location _destination);
        // to implement

    private:
        std::string passenger_name;
        Location origin;
        Location destination;
        std::string status;
};

#endif /* __TRIP_H__ */