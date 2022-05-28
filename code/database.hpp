#ifndef __DATABASE_H__
#define __DATABASE_H__

#include <vector>
#include <string>
#include <stdexcept>

#include "location.hpp"
#include "member.hpp"
#include "driver.hpp"
#include "passenger.hpp"
#include "trip.hpp"
#include "general.hpp"
#include "../defines.hpp"


class Database
{
    public:
        Database();
        void add_member(SignupCredentials new_mem);
        void add_location(Location* new_loc);
        void add_trip(TripRequestTokens new_trip, int _id);
        
        double calc_trip_cost(TripRequestTokens new_trip_tokens);


        void check_passenger_trip_errors(TripRequestTokens new_trip_tokens);
        void check_get_cost_errors(TripRequestTokens new_cost_tokens);
        void check_accept_errors(TripIntractTokens new_accpet_tokens);
        void check_finish_errors(TripIntractTokens new_finish_tokens);
        void check_delete_trip_errors(TripIntractTokens new_delete_trip_tokens);
        void check_member_is_available(std::string _username);
        void check_user_exist(std::string _username);
        void check_location_is_available(std::string loc_name);
        void check_trip_is_available(int _id);
        void check_trip_is_deleted(int _id);
        void check_trip_is(std::string status, int _id);
        
        void check_delete_another_user_trip(TripIntractTokens new_delete_trip_tokens);
        void check_finish_another_user_trip(TripIntractTokens new_finish_trip_tokens);
        void check_is_passenger(std::string _username);
        void check_is_driver(std::string _username);
        void check_member_is(bool status, std::string _username);
        int find_member_index(std::string member_name);
        int find_location_index(std::string location_name);
        int find_trip_index(int _id);
        Member* find_passenger_by_trip(int _id);
        Member* find_driver_by_trip(int _id);
        Member* find_member_by_username(std::string _username);
        Trip* find_trip_by_id(int _id);

        std::vector<Trip*> get_all_trips() { return trips; }
    private:
        std::vector<Location*> locations;
        std::vector<Member*> members;
        std::vector<Trip*> trips;
};


#endif /* __DATABASE_H__ */