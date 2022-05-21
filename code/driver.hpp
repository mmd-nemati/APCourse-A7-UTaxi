#ifndef __DRIVER_H__
#define __DRIVER_H__

#include <string>

#include "member.hpp"

class Driver : public Member
{
    public:
        Driver() {};
        Driver(std::string _username);
};

#endif /* __DRIVER_H__ */