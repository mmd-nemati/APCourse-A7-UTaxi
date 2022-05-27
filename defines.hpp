#ifndef __DEFINES_H__
#define __DEFINES_H__

#include <string>

constexpr double LENGTH_OF_A_DEGREE = 110.5;

const std::string LOCATION_TOKENS_DELIMITER = ",";
const std::string COMMAND_TOKENS_DELIMITER = " ";
const std::string TRIPS_DATA_DELIMITER = " ";
const std::string GET = "GET";
const std::string POST = "POST";
const std::string DELETE = "DELETE";
const std::string TRIP_WAITING = "waiting";
const std::string TRIP_TRAVELING = "traveling";
const std::string TRIP_FINISHED = "finished";
const std::string TRIP_DELETED = "deleted";

constexpr bool MEMBER_TRAVELING = true;
constexpr bool MEMBER_NOT_TRAVELING = false;

namespace WebCommand
{
    enum Command
    {
        W_NONE,
        GET,
        POST,
        DELETE 
    };
}

namespace POSTCommand
{
    enum Command
    {
        P_NONE,
        SIGNUP,
        REQUEST,
        ACCEPT,
        FINISH
    };
}

namespace GETCommand
{
    enum Command
    {
        G_NONE,
        TRIPS_LIST,
        TRIP_DATA
    };
}

namespace DELETECommand
{
    enum Command
    {
        D_NONE,
        TRIPS
    };
}

#endif /* __DEFINES_H__ */