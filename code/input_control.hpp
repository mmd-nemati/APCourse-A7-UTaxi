#ifndef __INPUT_CONTROL_H__
#define __INPUT_CONTROL_H__

#include <string>
#include <stdexcept>
#include "general.hpp"

class InputControl
{
    public:
        InputControl();
        void receive();
        WebCommand::Command detect_command();
        POSTCommand::Command post_command_handle();
        GETCommand::Command get_command_handle();

        SignupCredentials send_signup_credentials();
        TripRequestTokens send_trip_req_tokens();
        TripIntractTokens send_accpet_finish_tokens();
    private:
        std::string line;
        std::vector<std::string> tokens;
};

#endif /* __INPUT_CONTROL_H__ */