#ifndef __MEMBER_H__
#define __MEMBER_H__

#include <string>

#include "../defines.hpp"

class Member
{
    public:
        Member() {};
        bool is_same_as(std::string new_username);
        void start_to_travel();
        bool is_traveling();
        virtual bool is_passenger() = 0;
        virtual bool is_driver() = 0;
        // to implement

    protected:
        std::string username;
        bool status;
};

#endif /* __MEMBER_H__ */