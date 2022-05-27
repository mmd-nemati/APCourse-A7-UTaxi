#ifndef __LOCATION_H__
#define __LOCATION_H__

#include <string>

class Location
{
    public:
        Location();
        Location(std::string _name, double _lat, double _long, int _traffic);
        bool is_same_as(std::string check_loc);

        std::string get_name() { return name; }
    private:
        std::string name;
        double latitude;
        double longitude;
        int traffic;
};

#endif /* __LOCATION_H__ */