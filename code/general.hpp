#ifndef __GENERAL_H__
#define __GENERAL_H__

#include <vector>
#include <string>

#include "../defines.hpp"

std::vector<std::string> parse_line(std::string line, std::string delimiter);
struct SignupCredentials 
{
    std::string username = "NULL";
    std::string role = "NULL";
};

struct TripRequestTokens
{
    std::string username = "NULL";
    std::string origin_name = "NULL";
    std::string destination_name = "NULL";
};

#endif /* __GENERAL_H__ */