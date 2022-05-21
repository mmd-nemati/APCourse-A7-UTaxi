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

command::WebCommand InputControl::detect_command()
{
    try
    {
        if(tokens[0] == GET)
            return command::GET;
        else if(tokens[0] == POST)
            return command::POST;
        else if(tokens[0] == DELETE)
            return command::DELETE;
        
        else
            throw std::runtime_error("Bad Request");
    }
    catch(std::runtime_error& er)
    {
        std::cerr << er.what() << std::endl;
    }
}

void InputControl::post_command_handle()
{
    if(tokens[1] == "signup")
        std::cout << "signup" << std::endl;
}