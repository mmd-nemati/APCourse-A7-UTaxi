#ifndef __DEFINES_H__
#define __DEFINES_H__

#include <string>

const std::string LOCATION_TOKENS_DELIMITER = ",";
const std::string COMMAND_TOKENS_DELIMITER = " ";
const std::string GET = "GET";
const std::string POST = "POST";
const std::string DELETE = "DELETE";

namespace command
{
    enum WebCommand
    {
        GET = 1,
        POST = 2,
        DELETE = 3
    };
}
#endif /* __DEFINES_H__ */