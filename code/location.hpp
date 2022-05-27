#ifndef __LOCATION_H__
#define __LOCATION_H__

#include <string>
#include <cmath>

#include "../defines.hpp"
#include "general.hpp"
class Location
{
    public:
        Location();
        Location(std::string _name, double _lat, double _long, int _traffic);
        bool is_same_as(std::string check_loc);
        double calc_distance(Location* loc2);
        int calc_traffic_factor(Location* loc2);
        
        std::string get_name() { return name; }
    private:
        std::string name;
        double latitude;
        double longitude;
        int traffic;
};

#endif /* __LOCATION_H__ */