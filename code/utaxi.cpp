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
}