#ifndef __DEFINES_H__
#define __DEFINES_H__

#include <string>

const std::string LOCATION_TOKENS_DELIMITER = ",";
const std::string COMMAND_TOKENS_DELIMITER = " ";
const std::string GET = "GET";
const std::string POST = "POST";
const std::string DELETE = "DELETE";

namespace Command
{
    enum WebCommand
    {
        W_NONE = 0,
        GET = 1,
        POST = 2,
        DELETE = 3
    };

    enum AppCommand
    {
        A_NONE = 0,
        SIGNUP = 1,
        TRIPS = 2,
        ACCEPT = 3,
        FINISH = 4
    };
}

#endif /* __DEFINES_H__ */