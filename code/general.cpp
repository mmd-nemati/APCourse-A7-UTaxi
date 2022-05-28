#include "general.hpp"

std::vector<std::string> parse_line(std::string line, std::string delimiter)
{
    std::vector<std::string> tokens;
    size_t pos = 0;
    while ((pos = line.find(delimiter)) != std::string::npos) 
    {
        tokens.push_back(line.substr(0, pos));
        line.erase(0, pos + delimiter.length());
    }
    tokens.push_back(line.substr(0, pos));

    return tokens;
}

double calc_linear_dist(double lat1, double long1, double lat2, double long2)
{
    return (sqrt(pow(lat2 - lat1, 2) + pow(long2 - long1, 2)));
}