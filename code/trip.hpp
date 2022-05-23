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
        void start();
        void finish();
        void delete_yourself();
        bool is_deleted();
        bool is_started();
        bool is_finished();
        Member* get_passenger() { return passenger; }
        Location* get_origin() { return origin; }
        Location* get_destination() { return destination;}
        std::string get_status() { return status; }
        int get_id() { return trip_id; }
        // to implement

    private:
        Member* passenger;
        Location* origin;
        Location* destination;
        std::string status;
        int trip_id;
};

#endif /* __TRIP_H__ */