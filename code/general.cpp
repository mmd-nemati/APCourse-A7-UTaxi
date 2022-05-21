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