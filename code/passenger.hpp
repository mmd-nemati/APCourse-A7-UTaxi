#ifndef __PASSENGER_H__
#define __PASSENGER_H__

#include <string>

#include "member.hpp"

class Passenger : public Member
{
    public:
        Passenger() {};
        Passenger(std::string _username);

    //private:


};
#endif /* __PASSENGER_H__ */