#ifndef __GENERAL_H__
#define __GENERAL_H__

#include <vector>
#include <string>
#include <cmath>

#include "../defines.hpp"

std::vector<std::string> parse_line(std::string line, std::string delimiter);
double calc_linear_dist(double lat1, double long1, double lat2, double long2);
bool has_id(std::vector<std::string> tokens);
bool has_cost_sort(std::vector<std::string> tokens);
struct SignupCredentials 
{
    std::string username = EMPTY_ARG;
    std::string role = EMPTY_ARG;
};

struct TripRequestTokens
{
    std::string username = EMPTY_ARG;
    std::string origin_name = EMPTY_ARG;
    std::string destination_name = EMPTY_ARG;
    std::string in_hurry = EMPTY_ARG;
};

struct TripIntractTokens
{
    std::string username = EMPTY_ARG;
    int id = -1;
    std::string cost_sorted = EMPTY_ARG;
};

#endif /* __GENERAL_H__ */