#ifndef __UTAXI_H__
#define __UTAXI_H__

#include <vector>
#include <string>
#include "database.hpp"
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
        void run_u();
        void post_u();
        void get_u();
        void web_delete();

        void signup(SignupCredentials new_signup);
        void post_trips(TripRequestTokens new_trip_tokens);
        void accept();
        void finish();
        void trips_list();
        void trip_data();
        void delete_trip();

        int get_cost(TripRequestTokens new_cost_tokens);
        int get_trips_count() { return trips_counter; }
        std::vector<Location*> get_locs() { return database.get_locs(); }
    private:
        InputControl input;
        OutputControl output;
        Database database;
        int trips_counter;

        void check_signup_role(std::string role);
        void check_signup_username(std::string username);
        void check_new_trip_arguments(TripRequestTokens new_trip_tokens);
};

#endif /* __UTAXI_H__ */