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
    
    return Command::A_NONE;
}

SignupCredentials InputControl::get_signup_credentials()
{
    SignupCredentials new_signup;
    if(tokens[4] == "driver")
        new_signup = {tokens[3], "driver"};
    else if(tokens[4] == "passenger")
        new_signup = {tokens[3], "passenger"};

    return new_signup;
}