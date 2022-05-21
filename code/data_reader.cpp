#include "data_reader.hpp"

DataReader::DataReader()
{
    locs_num = 0;
}

void DataReader::read(std::string file_address)
{
    std::ifstream locs_data_file;
    locs_data_file.open(file_address);
    std::string line;
    std::getline(locs_data_file, line);

    while(getline(locs_data_file, line))
        {
            locs_raw_data.push_back(line);
            locs_num++;
        }
}

std::vector<std::string> DataReader::provide_loc_raw_data(int index)
{
    std::vector<std::string> tokens;
    size_t pos = 0;
    std::string line = locs_raw_data[index];
    while ((pos = line.find(TOKENS_DELIMITER)) != std::string::npos) 
    {
        tokens.push_back(line.substr(0, pos));
        line.erase(0, pos + TOKENS_DELIMITER.length());
    }
    tokens.push_back(line.substr(0, pos));

    return tokens;
}

