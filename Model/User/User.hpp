//#ifndef USER_H
//#define USER_H

#pragma once
#include<string>
#include"Node.hpp"

class User
{
    public:
        User(const std::string& nickname, const std::string& password, const std::string& firstName, const std::string& lastName);

        const std::string& getNickname()const;
        void setNickname (const std::string& nickname);
        const std::string& getPassword()const;
        void setPassword (const std::string& password);
        const std::string& getFirstName()const;
        void setFirstName (const std::string& firstName);
        const std::string& getLastName()const;
        void setLastName (const std::string& lastName);

        Node* getRootNode()const;


    protected:

    private:
        std::string m_nickname;
        std::string m_password;
        std::string m_firstName;
        std::string m_lastName;
        Node * m_rootNode;
};

//#endif // USER_H
