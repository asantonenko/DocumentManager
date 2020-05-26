#pragma once

#include"../../Enums/DMEnums.h"
#include "User.hpp"


class IUserObserver
{
    public:
        /** Default destructor */
        virtual ~IUserObserver() = default;

        virtual void onUserChanged (User* user,  Action action, UserProp up, const std::string& oldValue, const std::string& newValue)=0;
};
