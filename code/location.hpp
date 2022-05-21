#ifndef __LOCATION_H__
#define __LOCATION_H__

#include <string>

class Location
{
    public:
        Location();
        Location(std::string _name, double _lat, double _long);

        // delete?
        std::string get_name() { return name; }
        double get_lat() { return latitude; }
        double get_long() { return longitude; }
    private:
        std::string name;
        double latitude;
        double longitude;
};

#endif /* __LOCATION_H__ */