#include <iostream>
#include "utaxi.hpp"
Utaxi::Utaxi()
{
    ;
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
        input.receive();
        //if(input.detect_command() == Command::GET)
        //   std::cout << "yes" << std::endl;
        if (input.detect_command() == Command::POST)
            post();
            //std::cout << "post" << std::endl;
    }
}

void Utaxi::post()
{
    Command::AppCommand command = input.post_command_handle();
    if(command == Command::SIGNUP)
        signup();
}

void Utaxi::signup()
{
    SignupCredentials new_signup = input.get_signup_credentials();
    try
    {
        check_user_exist(new_signup);
        check_signup_role(new_signup);
    }
    catch(std::runtime_error& er)
    {
        std::cerr << er.what() << std::endl;
        return;
    }
    if(new_signup.role == "driver")
        members.push_back(new Driver(new_signup.username));
    if(new_signup.role == "passenger")
        members.push_back(new Passenger(new_signup.username));
    std::cout << "OK" << std::endl;
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