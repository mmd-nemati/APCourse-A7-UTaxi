#ifndef __MEMBER_H__
#define __MEMBER_H__

#include <string>

class Member
{
    public:
        Member() {};
        bool is_same_as(std::string new_username);
        // to implement

    protected:
        std::string username;
};

#endif /* __MEMBER_H__ */