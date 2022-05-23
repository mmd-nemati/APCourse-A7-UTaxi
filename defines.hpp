#ifndef __DEFINES_H__
#define __DEFINES_H__

#include <string>

const std::string LOCATION_TOKENS_DELIMITER = ",";
const std::string COMMAND_TOKENS_DELIMITER = " ";
const std::string TRIPS_DATA_DELIMITER = " ";
const std::string GET = "GET";
const std::string POST = "POST";
const std::string DELETE = "DELETE";
const std::string TRIP_WAITING = "waiting";
const std::string TRIP_TRAVELING = "traveling";
const std::string TRIP_FINISHED = "finished";
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
        TRIP
    };
}
/*namespace Command
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
        FINISH = 4,
    };
}

*/
#endif /* __DEFINES_H__ */