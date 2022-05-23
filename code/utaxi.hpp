#ifndef __UTAXI_H__
#define __UTAXI_H__

#include <vector>
#include <string>

#include "data_reader.hpp"
#include "location.hpp"
#include "input_control.hpp"
#include "output_control.hpp"
#include "member.hpp"
#include "driver.hpp"
#include "passenger.hpp"
#include "trip.hpp"

class Utaxi
{
    public:
        Utaxi();
        void gather_loc_data(std::string file_address);
        void run();
        void post();
        void get();
        void web_delete();

        void signup();
        void post_trips();
        void accept();
        void finish();
        void trips_list();
        void trip_data();
        void delete_trip();
        
        
        void check_user_exist(SignupCredentials new_signup);
        void check_signup_role(SignupCredentials new_signup);
        void check_new_trip_arguments(TripRequestTokens new_trip_tokens);
        void check_member_traveling(std::string _username);
        void check_member_not_traveling(std::string _username);
        void check_is_passenger(std::string _username);
        void check_is_driver(std::string _username);
        void check_post_trips_errors(TripRequestTokens new_trip_tokens);
        //void check_accept_finish_tokens_not_found(TripIntractTokens new_tokens);
        void check_accept_errors(TripIntractTokens new_accept_tokens);
        void check_finish_errors(TripIntractTokens new_finish_tokens);
        void check_trip_is_available(int _id);
        void check_trip_is_deleted(int _id);
        void check_trip_is_started(int _id);
        void check_trip_is_finished(int _id);
        void check_delete_another_user_trip(TripIntractTokens new_delete_trip_tokens);
        void check_member_is_available(std::string username);
        void check_location_is_available(std::string loc_name);
        //void travel_begins(TripRequestTokens new_trip_tokens);
        int find_member_index(std::string member_name);
        int find_location_index(std::string location_name);
        int find_trip_index(int _id);
        Member* find_passenger_by_trip(int _id);

    private:
        InputControl input;
        OutputControl output;
        std::vector<Location*> locations;
        std::vector<Member*> members;
        std::vector<Trip*> trips;
        Member* find_member();
        int trips_counter;

};

#endif /* __UTAXI_H__ */