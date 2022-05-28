#ifndef __TRIP_H__
#define __TRIP_H__

#include <string>
#include "location.hpp"
#include "member.hpp"
#include "../defines.hpp"

class Trip
{
    public:
        Trip() {};
        Trip(Member* _passenger, Location* _origin, Location* _destination, int _id);
        
        bool is_same_as(int _id);
        double calc_price();
        void start();
        void finish();
        void delete_yourself();
        bool is_deleted();
        bool is_status(std::string in_stat);

        void set_driver(Member* _driver) { driver = _driver; }
        Member* get_passenger() { return passenger; }
        Member* get_driver() { return driver; }
        Location* get_origin() { return origin; }
        Location* get_destination() { return destination;}
        std::string get_status() { return status; }
        int get_id() { return trip_id; }

    private:
        Member* passenger;
        Member* driver;
        Location* origin;
        Location* destination;
        std::string status;
        int trip_id;
        double price = 0;
};

#endif /* __TRIP_H__ */