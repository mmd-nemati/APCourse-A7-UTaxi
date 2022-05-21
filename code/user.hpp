#ifndef __USER_H__
#define __USER_H__

#include <string>

#include "member.hpp"

class User : public Member
{
    public:
        User() {};
        User(std::string _username);

    //private:


};
#endif /* __USER_H__ */