#ifndef __UTAXI_H__
#define __UTAXI_H__

#include <vector>
#include <string>

#include "data_reader.hpp"
#include "location.hpp"
#include "input_control.hpp"
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
        void signup();
        void post_trips();
        void accept();
        void finish();
        void check_user_exist(SignupCredentials new_signup);
        void check_signup_role(SignupCredentials new_signup);
        void check_new_trip_arguments(TripRequestTokens new_trip_tokens);
        void check_new_trip_tokens_not_found(TripRequestTokens new_trip_tokens);
        void check_member_traveling(std::string _username);
        void check_member_not_traveling(std::string _username);
        void check_is_passenger(std::string _username);
        void check_is_driver(std::string _username);
        void check_post_trips_errors(TripRequestTokens new_trip_tokens);
        void check_accept_finish_tokens_not_found(TripIntractTokens new_tokens);
        void check_accept_errors(TripIntractTokens new_accept_tokens);
        void check_finish_errors(TripIntractTokens new_finish_tokens);
        //void travel_begins(TripRequestTokens new_trip_tokens);
        int find_member_index(std::string member_name);
        int find_location_index(std::string location_name);
        int find_trip_index(int _id);
        Member* find_passenger_by_trip(int _id);

    private:
        InputControl input;
        std::vector<Location*> locations;
        std::vector<Member*> members;
        std::vector<Trip*> trips;
        Member* find_member();
        int trips_counter;

};

#endif /* __UTAXI_H__ */