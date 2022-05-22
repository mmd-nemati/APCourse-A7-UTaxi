#ifndef __PASSENGER_H__
#define __PASSENGER_H__

#include <string>

#include "member.hpp"
#include "../defines.hpp"

class Passenger : public Member
{
    public:
        Passenger() {};
        Passenger(std::string _username);
        virtual bool is_passenger() { return true; }
};
#endif /* __PASSENGER_H__ */