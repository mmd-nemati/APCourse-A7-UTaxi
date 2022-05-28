#include <iostream>
#include "utaxi.hpp"

Utaxi::Utaxi()
{
    trips_counter = 0;
}

void Utaxi::gather_loc_data(std::string file_address)
{
    std::vector<std::string> tokens;
    DataReader loc_reader;
    loc_reader.read(file_address);
    for(int i = 0; i < loc_reader.get_locs_num(); i++)
    {
        tokens = loc_reader.provide_loc_raw_data(i);
        Location* new_loc = new Location(tokens[0], stod(tokens[1]), stod(tokens[2]), stoi(tokens[3]));
        database.add_location(new_loc);
    }
}

void Utaxi::run()
{
    while(input.receive())
    {
        try
        {
            if (input.detect_command() == WebCommand::POST)
                post();
            else if(input.detect_command() == WebCommand::GET)
                get();
            else if(input.detect_command() == WebCommand::DELETE)
                web_delete();
            else if (input.detect_command() == WebCommand::W_NONE)
                break;
        }
        catch(std::runtime_error& er)
        {
            output.error(er);
        }
    }
}

void Utaxi::post()
{
    POSTCommand::Command command = input.post_command_handle();
    if(command == POSTCommand::SIGNUP)
        signup();
    else if(command == POSTCommand::REQUEST)
        post_trips();
    else if(command == POSTCommand::ACCEPT)
        accept();
    else if(command == POSTCommand::FINISH)
        finish();
    else
        throw std::runtime_error("Not Found");
}

void Utaxi::get()
{
    GETCommand::Command command = input.get_command_handle();
    if(command == GETCommand::TRIPS_LIST)
        trips_list();
    else if(command == GETCommand::TRIP_DATA)
        trip_data();
    else if(command == GETCommand::COST)
        get_cost();
    
    else
        throw std::runtime_error("Not Found");
}

void Utaxi::web_delete()
{
    DELETECommand::Command command = input.delete_command_handle();
    if(command == DELETECommand::TRIPS)
        delete_trip();
    else
        throw std::runtime_error("Not Found");
}

void Utaxi::signup()
{
    SignupCredentials new_signup = input.send_signup_credentials();

    check_signup_role(new_signup);
    database.check_user_exist(new_signup.username);
    database.add_member(new_signup);

    output.done();
}

void Utaxi::post_trips()
{
    TripRequestTokens new_trip_tokens = input.send_trip_req_tokens();
    check_new_trip_arguments(new_trip_tokens);
    database.check_passenger_trip_errors(new_trip_tokens);

    trips_counter++;
    database.add_trip(new_trip_tokens, trips_counter);

    output.trip_id(trips_counter);
}

void Utaxi::accept()
{
    TripIntractTokens new_accpet_tokens = input.send_accpet_finish_tokens();
    database.check_accept_errors(new_accpet_tokens);

    database.find_passenger_by_trip(new_accpet_tokens.id)->start_to_travel();
    database.find_member_by_username(new_accpet_tokens.username)->start_to_travel();
    database.find_trip_by_id(new_accpet_tokens.id)->start();
    database.find_trip_by_id(new_accpet_tokens.id)->set_driver(database.find_member_by_username(new_accpet_tokens.username));
    
    output.done();
}

void Utaxi::finish()
{
    TripIntractTokens new_finish_tokens = input.send_accpet_finish_tokens();
    database.check_finish_errors(new_finish_tokens);

    database.find_passenger_by_trip(new_finish_tokens.id)->stop_travel();
    database.find_member_by_username(new_finish_tokens.username)->stop_travel();
    database.find_trip_by_id(new_finish_tokens.id)->finish();
   
    output.done();
}

void Utaxi::trips_list()
{
    TripIntractTokens new_trips_list_tokens = input.send_get_trips_tokens();
    database.check_is_driver(new_trips_list_tokens.username);
    output.trips_list(database.get_trips(new_trips_list_tokens.cost_sorted));
}

void Utaxi::trip_data()
{
    TripIntractTokens new_trip_data_tokens = input.send_get_trips_tokens();
    database.check_is_driver(new_trip_data_tokens.username);
    database.check_trip_is_available(new_trip_data_tokens.id);

    output.trip_data(database.find_trip_by_id(new_trip_data_tokens.id));
}

void Utaxi::get_cost()
{
    TripRequestTokens new_cost_tokens = input.send_trip_req_tokens();
    database.check_passenger_trip_errors(new_cost_tokens);

    double cost = database.calc_trip_cost(new_cost_tokens);

    output.cost(cost);
}

void Utaxi::delete_trip()
{
    TripIntractTokens new_delete_trip_tokens = input.send_delete_trip_tokens();
    database.check_delete_trip_errors(new_delete_trip_tokens);

    database.find_trip_by_id(new_delete_trip_tokens.id)->delete_yourself();
   
    output.done();
}

void Utaxi::check_signup_role(SignupCredentials new_signup)
{
    if(new_signup.role != "driver" && new_signup.role != "passenger")
        throw std::runtime_error("Bad Request");
}

void Utaxi::check_new_trip_arguments(TripRequestTokens new_trip_tokens)
{
    if(new_trip_tokens.username == "NULL" || new_trip_tokens.origin_name == "NULL" ||
        new_trip_tokens.destination_name == "NULL" || new_trip_tokens.in_hurry == "NULL")
            throw std::runtime_error("Bad Request");
}