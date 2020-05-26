#include "UserView.hpp"
#include <iostream>

UserView::UserView()
{
    //ctor
}

void UserView::onUserChanged (User* user,  Action action, UserProp up, const std::string& oldValue, const std::string& newValue){
    switch (action)
    {
    case A_Create:
        if (up==UP_User)
        {
            std::cout <<"User created: "; printUser (user); std::cout <<std::endl;
        }
        break;
    case A_Delete:
        if (up==UP_User)
        {
            std::cout <<"User deleting: "; printUser (user); std::cout <<std::endl;
        }
        break;
    case A_Update:
        std::cout <<"User updated: "; printUser (user); std::cout <<" ";
        switch (up){
        case UP_FirstName:
            std::cout <<"firstName";
            break;
        case UP_LastName:
            std::cout <<"lastName";
            break;
        case UP_Nickname:
            std::cout <<"nickname";
            break;
        case UP_Password:
            std::cout <<"password";
            break;
        }
        std::cout <<" "<< oldValue <<"->" <<newValue <<std::endl;
        break;
    case A_Login:
        std::cout <<"User login: "; printUser (user); std::cout <<std::endl;
        break;
    case A_Logout:
        std::cout <<"User logout: "; printUser (user); std::cout <<std::endl;
        break;
    }
}

void UserView::printUser(User* user){
    std::cout <<"User " <<user->getNickname() << " (" <<user->getFirstName() <<" " <<user->getLastName() <<")";
}
