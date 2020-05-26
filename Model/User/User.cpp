#include "User.hpp"

User::User(const std::string& nickname, const std::string& password, const std::string& firstName, const std::string& lastName)
    : m_nickname(nickname), m_password (password), m_firstName (firstName), m_lastName (lastName)
{
    //ctor
}

const std::string& User::getNickname()const{
    return m_nickname;
}
void User::setNickname (const std::string& nickname){
    m_nickname = nickname;
}
const std::string& User::getPassword()const{
    return m_password;
}

void User::setPassword (const std::string& password){
    m_password = password;
}

const std::string& User::getFirstName()const{
    return m_firstName;
}

void User::setFirstName (const std::string& firstName){
    m_firstName = firstName;
}

const std::string& User::getLastName()const{
    return m_lastName;
}

void User::setLastName (const std::string& lastName){
    m_lastName = lastName;
}

Node* User::getRootNode()const
{
    return m_rootNode;
}
