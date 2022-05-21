#include "member.hpp"

bool Member::is_same_as(std::string new_username)
{
    return (this->username == new_username);
}