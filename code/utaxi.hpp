#ifndef __UTAXI_H__
#define __UTAXI_H__

#include <vector>
#include <string>

#include "data_reader.hpp"
#include "location.hpp"
#include "input_control.hpp"
#include "member.hpp"

class Utaxi
{
    public:
        Utaxi();
        void gather_loc_data(std::string file_address);
        void run();
        void post();
        // to implement

    private:
        InputControl input;
        std::vector<Location*> locations;
        std::vector<Member*> members;

};

#endif /* __UTAXI_H__ */