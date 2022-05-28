#include <iostream>

#include "input_control.hpp"

InputControl::InputControl()
{
    ;
}

bool InputControl::receive()
{
    if(std::getline(std::cin, line))
    {
        tokens = parse_line(line, COMMAND_TOKENS_DELIMITER);
        return true;
    }
    return false;
}

WebCommand::Command InputControl::detect_command()
{
    if(tokens[0] == GET)
        return WebCommand::GET;
    else if(tokens[0] == POST)
        return WebCommand::POST;
    else if(tokens[0] == DELETE)
        return WebCommand::DELETE;
    else if(tokens[0] == "")
        return WebCommand::W_NONE;

    else
        throw std::runtime_error("Bad Request");

    return WebCommand::W_NONE;
}

POSTCommand::Command InputControl::post_command_handle()
{
    if(tokens[1] == "signup")
        return POSTCommand::SIGNUP;
    else if(tokens[1] == "trips")
        return POSTCommand::REQUEST;
    else if(tokens[1] == "accept")
        return POSTCommand::ACCEPT;
    else if(tokens[1] == "finish")
        return POSTCommand::FINISH;

    return POSTCommand::P_NONE;
}

GETCommand::Command InputControl::get_command_handle()
{
    if(tokens[1] == "trips" && tokens.size() == 5)
        return GETCommand::TRIPS_LIST;
    else if(tokens[1] == "trips" && tokens.size() == 7)
        return GETCommand::TRIP_DATA;
    else if(tokens[1] == "cost")
        return GETCommand::COST;
    
    return GETCommand::G_NONE;
}

DELETECommand::Command InputControl::delete_command_handle()
{
    if(tokens[1] == "trips")
        return DELETECommand::TRIPS;

    return DELETECommand::D_NONE;
}

SignupCredentials InputControl::send_signup_credentials()
{
    SignupCredentials new_signup;
    for(int i = 3; i < tokens.size()-1; i++)
    {
        if(tokens[i] == "username")
            new_signup.username = tokens[i+1];
        if(tokens[i] == "role")
            new_signup.role = tokens[i+1];
    }
    return new_signup;
}

TripRequestTokens InputControl::send_trip_req_tokens()
{
    TripRequestTokens new_trip;
    for(int i = 3; i < tokens.size()-1; i++)
    {
        if(tokens[i] == "username")
            new_trip.username = tokens[i+1];
        if(tokens[i] == "origin")
            new_trip.origin_name = tokens[i+1];
        if(tokens[i] == "destination")
            new_trip.destination_name = tokens[i+1];
        if(tokens[i] == "in_hurry")
            new_trip.in_hurry = tokens[i+1];
    }
    return new_trip;
}

TripIntractTokens InputControl::send_accpet_finish_tokens()
{
    TripIntractTokens new_tokens;
    for(int i = 3; i < tokens.size(); i++)
    {
        if(tokens[i] == "username")
            new_tokens.username = tokens[i+1];
        if(tokens[i] == "id")
            new_tokens.id = stoi(tokens[i+1]);
    }
    return new_tokens;
}

TripIntractTokens InputControl::send_get_trips_tokens()
{
    TripIntractTokens new_tokens;
    for(int i = 3; i < tokens.size(); i++)
    {
        if(tokens[i] == "username")
            new_tokens.username = tokens[i+1];
        if(tokens[i] == "id")
            new_tokens.id = stoi(tokens[i+1]);
    }
    return new_tokens;
}

TripIntractTokens InputControl::send_delete_trip_tokens()
{
    TripIntractTokens new_tokens;
    for(int i = 3; i < tokens.size(); i++)
    {
        if(tokens[i] == "username")
            new_tokens.username = tokens[i+1];
        if(tokens[i] == "id")
            new_tokens.id = stoi(tokens[i+1]);
    }
    return new_tokens;
}