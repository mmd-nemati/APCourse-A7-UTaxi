#ifndef __UTAXI_H__
#define __UTAXI_H__

#include <vector>
#include <string>

#include "data_reader.hpp"
#include "location.hpp"
#include "input_control.hpp"
#include "member.hpp"
#include "driver.hpp"
#include "passenger.hpp"
#include "trip.hpp"

class Utaxi
{
    public:
        Utaxi();
        void gather_loc_data(std::string file_address);
        void run();
        void post();
        void signup();
        void check_user_exist(SignupCredentials new_signup);
        void check_signup_role(SignupCredentials new_signup);

    private:
        InputControl input;
        std::vector<Location*> locations;
        std::vector<Member*> members;
        std::vector<Trip*> trips;

};

#endif /* __UTAXI_H__ */