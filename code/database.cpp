#include "database.hpp"
#include <iostream>
Database::Database()
{
    ;
}

void Database::add_member(SignupCredentials new_mem)
{
    if(new_mem.role == "driver")
        members.push_back(new Driver(new_mem.username));
    if(new_mem.role == "passenger")
        members.push_back(new Passenger(new_mem.username));
}

void Database::add_location(Location* new_loc)
{
    locations.push_back(new_loc);
}

void Database::add_trip(TripRequestTokens new_tr, int _id)
{
    Trip* new_trip = new Trip(members[find_member_index(new_tr.username)],
                            locations[find_location_index(new_tr.origin_name)],
                            locations[find_location_index(new_tr.destination_name)],
                             _id);
    new_trip->calc_price();
    trips.push_back(new_trip);
}

void Database::check_post_trips_errors(TripRequestTokens new_trip_tokens)
{
    check_member_is_available(new_trip_tokens.username);
    check_location_is_available(new_trip_tokens.origin_name);
    check_location_is_available(new_trip_tokens.destination_name);
    check_is_passenger(new_trip_tokens.username);
    check_member_traveling(new_trip_tokens.username);
}

void Database::check_accept_errors(TripIntractTokens new_accpet_tokens)
{
    check_member_is_available(new_accpet_tokens.username);
    check_trip_is_available(new_accpet_tokens.id);
    check_trip_is_started(new_accpet_tokens.id);
    check_trip_is_finished(new_accpet_tokens.id);
    check_trip_is_deleted(new_accpet_tokens.id);
    check_is_driver(new_accpet_tokens.username);
    check_member_traveling(new_accpet_tokens.username);
}

void Database::check_finish_errors(TripIntractTokens new_finish_tokens)
{
    check_member_is_available(new_finish_tokens.username);
    check_trip_is_available(new_finish_tokens.id);
    check_trip_not_started(new_finish_tokens.id);
    check_is_driver(new_finish_tokens.username);
    check_member_not_traveling(new_finish_tokens.username);
    check_finish_another_user_trip(new_finish_tokens);
}

void Database::check_delete_trip_errors(TripIntractTokens new_delete_trip_tokens)
{
    check_trip_is_available(new_delete_trip_tokens.id);
    check_trip_is_deleted(new_delete_trip_tokens.id);
    check_trip_is_started(new_delete_trip_tokens.id);
    check_trip_is_finished(new_delete_trip_tokens.id);
    check_delete_another_user_trip(new_delete_trip_tokens);
}

void Database::check_member_is_available(std::string _username)
{
    if(find_member_index(_username) == -1)
        throw std::runtime_error("Not Found");
}

void Database::check_user_exist(std::string _username)
{
    if(find_member_index(_username) != -1)
        throw std::runtime_error("Bad Request");
}
void Database::check_location_is_available(std::string loc_name)
{
    if(find_location_index(loc_name) == -1)
        throw std::runtime_error("Not Found");
}

void Database::check_trip_is_available(int _id)
{
    if(find_trip_index(_id) == -1)
        throw std::runtime_error("Not Found");
}

void Database::check_trip_is_deleted(int _id)
{
    if(trips[find_trip_index(_id)]->is_deleted())
        throw std::runtime_error("Not Found");
}

void Database::check_trip_is_started(int _id)
{
    if(trips[find_trip_index(_id)]->is_started())
        throw std::runtime_error("Bad Request");
}

void Database::check_trip_not_started(int _id)
{
    if(!trips[find_trip_index(_id)]->is_started())
        throw std::runtime_error("Bad Request");
}

void Database::check_trip_is_finished(int _id)
{
    if(trips[find_trip_index(_id)]->is_finished())
        throw std::runtime_error("Bad Request");
}

void Database::check_delete_another_user_trip(TripIntractTokens new_delete_trip_tokens)
{
    if(!find_passenger_by_trip(new_delete_trip_tokens.id)->is_same_as(new_delete_trip_tokens.username))
        throw std::runtime_error("Permission Denied");
}

void Database::check_finish_another_user_trip(TripIntractTokens new_finish_tokens)
{
    if(!find_driver_by_trip(new_finish_tokens.id)->is_same_as(new_finish_tokens.username))
        throw std::runtime_error("Permission Denied");
}

void Database::check_is_passenger(std::string _username)
{
    if(!members[find_member_index(_username)]->is_passenger())
        throw std::runtime_error("Permission Denied");
}

void Database::check_is_driver(std::string _username)
{
    if(!members[find_member_index(_username)]->is_driver())
        throw std::runtime_error("Permission Denied");
}

void Database::check_member_traveling(std::string _username)
{
    if(members[find_member_index(_username)]->is_traveling())
        throw std::runtime_error("Bad Request");
}

void Database::check_member_not_traveling(std::string _username)
{
    if(!members[find_member_index(_username)]->is_traveling())
        throw std::runtime_error("Bad Request");
}

int Database::find_member_index(std::string member_name)
{
    for(int i = 0; i < members.size(); i++)
        if(members[i]->is_same_as(member_name))
            return i;
   
    return -1;
}

int Database::find_location_index(std::string location_name)
{
    for(int i = 0; i < locations.size(); i++)
        if(locations[i]->is_same_as(location_name))
            return i;

    return -1;
}

int Database::find_trip_index(int _id)
{
    for(int i = 0; i < trips.size(); i++)
        if(trips[i]->is_same_as(_id))
            return i;
    
    return -1;
}

Member* Database::find_passenger_by_trip(int _id)
{
    return (trips[find_trip_index(_id)]->get_passenger());
}

Member* Database::find_driver_by_trip(int _id)
{
    return (trips[find_trip_index(_id)]->get_driver());
}

Member* Database::find_member_by_username(std::string _username)
{
    return (members[find_member_index(_username)]);
}

Trip* Database::find_trip_by_id(int _id)
{
    return (trips[find_trip_index(_id)]);
}