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
        Location* new_loc = new Location(tokens[0], stod(tokens[1]), stod(tokens[2]));
        locations.push_back(new_loc);
    }

   // for(auto x : locations)
   //     std::cout << x->get_name() << std::endl;
}

void Utaxi::run()
{
    while(true)
    {
        try
        {
            input.receive();

            if (input.detect_command() == WebCommand::POST)
                post();
            else if(input.detect_command() == WebCommand::GET)
                get();
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
}

void Utaxi::signup()
{
    SignupCredentials new_signup = input.send_signup_credentials();
    check_user_exist(new_signup);
    check_signup_role(new_signup);

    if(new_signup.role == "driver")
        members.push_back(new Driver(new_signup.username));
    if(new_signup.role == "passenger")
        members.push_back(new Passenger(new_signup.username));
    output.done();
}

void Utaxi::post_trips()
{
    TripRequestTokens new_trip_tokens = input.send_trip_req_tokens();
    check_post_trips_errors(new_trip_tokens);

    trips_counter++;
    std::cout << trips_counter << std::endl;
    Trip* new_trip = new Trip(members[find_member_index(new_trip_tokens.username)],
            locations[find_location_index(new_trip_tokens.origin_name)],
            locations[find_location_index(new_trip_tokens.destination_name)], trips_counter);
    trips.push_back(new_trip);
}

void Utaxi::accept()
{
    TripIntractTokens new_accpet_tokens = input.send_accpet_finish_tokens();
    check_accept_errors(new_accpet_tokens);

    output.done();
    find_passenger_by_trip(new_accpet_tokens.id)->start_to_travel();
    members[find_member_index(new_accpet_tokens.username)]->start_to_travel();
    trips[find_trip_index(new_accpet_tokens.id)]->start();
}

void Utaxi::finish()
{
    TripIntractTokens new_finish_tokens = input.send_accpet_finish_tokens();
    check_finish_errors(new_finish_tokens);

    output.done();
    find_passenger_by_trip(new_finish_tokens.id)->stop_travel();
    members[find_member_index(new_finish_tokens.username)]->stop_travel();
    trips[find_trip_index(new_finish_tokens.id)]->finish();
}

void Utaxi::trips_list()
{
    TripIntractTokens new_trips_list_tokens = input.send_get_trips_tokens();
    check_is_driver(new_trips_list_tokens.username);
    output.trips_list(trips);
}

void Utaxi::check_user_exist(SignupCredentials new_signup)
{
    for(int i = 0; i < members.size(); i++)
        if(members[i]->is_same_as(new_signup.username))
            throw std::runtime_error("Bad Request");
}

void Utaxi::check_signup_role(SignupCredentials new_signup)
{
    if(new_signup.role != "driver" && new_signup.role != "passenger")
        throw std::runtime_error("Bad Request");
}

void Utaxi::check_post_trips_errors(TripRequestTokens new_trip_tokens)
{
    check_new_trip_arguments(new_trip_tokens);
    check_new_trip_tokens_not_found(new_trip_tokens);
    check_is_passenger(new_trip_tokens.username);
    check_member_traveling(new_trip_tokens.username);
}

void Utaxi::check_accept_errors(TripIntractTokens new_accpet_tokens)
{
    check_accept_finish_tokens_not_found(new_accpet_tokens);
    check_is_driver(new_accpet_tokens.username);
    check_member_traveling(new_accpet_tokens.username);
}

void Utaxi::check_finish_errors(TripIntractTokens new_finish_tokens)
{
    check_accept_finish_tokens_not_found(new_finish_tokens);
    check_is_driver(new_finish_tokens.username);
    check_member_not_traveling(new_finish_tokens.username);
}

void Utaxi::check_new_trip_arguments(TripRequestTokens new_trip_tokens)
{
    if(new_trip_tokens.username == "NULL" || new_trip_tokens.origin_name == "NULL" ||
        new_trip_tokens.destination_name == "NULL")
            throw std::runtime_error("Bad Request");
}

void Utaxi::check_new_trip_tokens_not_found(TripRequestTokens new_trip_tokens)
{
    bool user_exist = false;
    bool origin_exist = false;
    bool destination_exist = false;
     for(int i = 0; i < members.size(); i++)
        if(members[i]->is_same_as(new_trip_tokens.username))
            user_exist = true;
    
    for(int i = 0; i < locations.size(); i++)
        if(locations[i]->is_same_as(new_trip_tokens.origin_name))
            origin_exist = true;
    for(int i = 0; i < locations.size(); i++)
        if(locations[i]->is_same_as(new_trip_tokens.destination_name))
            destination_exist = true;

    if(user_exist == false || destination_exist == false || origin_exist == false)
        throw std::runtime_error("Not Found");
}  

void Utaxi::check_member_traveling(std::string _username)
{
    if(members[find_member_index(_username)]->is_traveling())
        throw std::runtime_error("Bad Request");
}

void Utaxi::check_member_not_traveling(std::string _username)
{
    if(!members[find_member_index(_username)]->is_traveling())
        throw std::runtime_error("Bad Request");
}

void Utaxi::check_is_passenger(std::string _username)
{
    if(members[find_member_index(_username)]->is_passenger() == false)
        throw std::runtime_error("Permission Denied");
}

void Utaxi::check_accept_finish_tokens_not_found(TripIntractTokens new_accpet_tokens)
{
    bool user_exist = false;
    bool trip_exist = false;
    for(int i = 0; i < members.size(); i++)
        if(members[i]->is_same_as(new_accpet_tokens.username))
            user_exist = true;

    for(int i = 0; i < trips.size(); i++)
        if(trips[i]->is_same_as(new_accpet_tokens.id))
            trip_exist = true;
    
    if(user_exist == false || trip_exist == false)
        throw std::runtime_error("Not Found");
}


void Utaxi::check_is_driver(std::string _username)
{
    if(members[find_member_index(_username)]->is_driver() == false)
        throw std::runtime_error("Permission Denied");
}

int Utaxi::find_member_index(std::string member_name)
{
    for(int i = 0; i < members.size(); i++)
        if(members[i]->is_same_as(member_name))
            return i;
   
    return -1;
}

int Utaxi::find_location_index(std::string location_name)
{
    for(int i = 0; i < locations.size(); i++)
        if(locations[i]->is_same_as(location_name))
            return i;

    return -1;
}

int Utaxi::find_trip_index(int _id)
{
    for(int i = 0; i < trips.size(); i++)
        if(trips[i]->is_same_as(_id))
            return i;
    
    return -1;
}

Member* Utaxi::find_passenger_by_trip(int _id)
{
    return (trips[find_trip_index(_id)]->get_passenger());
}