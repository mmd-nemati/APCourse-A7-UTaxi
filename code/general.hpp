#ifndef __GENERAL_H__
#define __GENERAL_H__

#include <vector>
#include <string>
#include <cmath>

#include "../defines.hpp"

std::vector<std::string> parse_line(std::string line, std::string delimiter);
double calc_linear_dist(double lat1, double long1, double lat2, double long2);

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
    std::string in_hurry = "NULL";
};

struct TripIntractTokens
{
    std::string username = "NULL";
    int id = -1;
};

#endif /* __GENERAL_H__ */