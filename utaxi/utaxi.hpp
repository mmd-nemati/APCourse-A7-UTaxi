#ifndef __UTAXI_H__
#define __UTAXI_H__

#include <vector>
#include <string>

#include "data_reader.hpp"
#include "location.hpp"

class Utaxi
{
    public:
        Utaxi();
        void gather_loc_data(std::string file_address);
        // to implement

    private:
        std::vector<Location*> locations;
        // to implement
};

#endif /* __UTAXI_H__ */