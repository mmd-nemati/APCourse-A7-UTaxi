#include "member.hpp"

bool Member::is_same_as(std::string new_username)
{
    return (this->username == new_username);
}

bool Member::is_traveling()
{
    return (status == MEMBER_TRAVELING);
}

/*void Member::start_to_travel()
{
    status = MEMBER_TRAVELING;
}*/