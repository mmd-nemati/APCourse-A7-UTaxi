#include <iostream>

#include "input_control.hpp"

InputControl::InputControl()
{
    ;
}

void InputControl::receive()
{
    std::getline(std::cin, line);
    tokens = parse_line(line, COMMAND_TOKENS_DELIMITER);
}

Command::WebCommand InputControl::detect_command()
{
    try
    {
        if(tokens[0] == GET)
            return Command::GET;
        else if(tokens[0] == POST)
            return Command::POST;
        else if(tokens[0] == DELETE)
            return Command::DELETE;
        
        else
            throw std::runtime_error("Bad Request");
    }
    catch(std::runtime_error& er)
    {
        std::cerr << er.what() << std::endl;
    }

    return Command::W_NONE;
}

Command::AppCommand InputControl::post_command_handle()
{
    if(tokens[1] == "signup")
        return Command::SIGNUP;
    else if(tokens[1] == "trips")
        return Command::TRIPS;
    else if(tokens[1] == "accept")
        return Command::ACCEPT;
    
    return Command::A_NONE;
}

SignupCredentials InputControl::get_signup_credentials()
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

TripRequestTokens InputControl::get_trip_tokens()
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
    }
    return new_trip;
}

AccpetTokens InputControl::get_accpet_tokens()
{
    AccpetTokens new_accpet;
    for(int i = 3; i < tokens.size(); i++)
    {
        if(tokens[i] == "username")
            new_accpet.username = tokens[i+1];
        if(tokens[i] == "id")
            new_accpet.id = stoi(tokens[i+1]);
    }
    return new_accpet;
}