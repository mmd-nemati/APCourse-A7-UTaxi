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
        Command::WebCommand detect_command();
        Command::AppCommand post_command_handle();
        SignupCredentials get_signup_credentials();
    
    private:
        std::string line;
        std::vector<std::string> tokens;
};

#endif /* __INPUT_CONTROL_H__ */