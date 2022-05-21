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
        command::WebCommand detect_command();
        void post_command_handle();
       // void 
        // to implement
    
    private:
        std::string line;
        std::vector<std::string> tokens;
        // to implement
};

#endif /* __INPUT_CONTROL_H__ */