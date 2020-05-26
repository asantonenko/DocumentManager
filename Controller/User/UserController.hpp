#pragma once

#include<map>
#include<vector>
#include<set>
#include<string>
#include"User.hpp"
#include"DirectoryController.hpp"
#include"IUserObserver.h"


class UserController
{
    public:
        /** Default constructor */
        UserController();
        ~UserController();
        User* createUser(const std::string& nick, const std::string& password, const std::string& firstName, const std::string& lastName);
        User* login(const std::string& nick, const std::string& password);
        User* logout(User* user);
        bool remove(User* user);
        User* changePassword(User* user, const std::string& password);
        User* changeInfo(User* user, const std::string& firstName, const std::string& lastName);
        DirectoryController* controllerFor(User* user);

        void addObserver (IUserObserver * observer);
        void removeObserver (IUserObserver * observer);

        void sendEvent(User* user,  Action action, UserProp up, const std::string& oldValue = "", const std::string& newValue = "");

    protected:

    private:
        std::set<User*> m_allUsers;
        std::map<User*,DirectoryController*> m_activeUsers;
        std::set<IUserObserver*> m_observers;

        std::set<User*>::iterator findUser(User* user);

};
