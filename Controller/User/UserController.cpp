#include "UserController.hpp"

UserController::UserController()
{
    //ctor
}

UserController::~UserController(){

}


User* UserController::createUser(const std::string& nick, const std::string& password, const std::string& firstName, const std::string& lastName){
    User * newUser = new User (nick,password,firstName, lastName);
    m_allUsers.insert(newUser);
    sendEvent(newUser,A_Create,UP_User);
    return newUser;
}

User* UserController::login(const std::string& nick, const std::string& password) {
    for (User* user: m_allUsers)
    {
        if (user->getNickname() == nick)
        {
            if (user->getPassword() == password)
            {
                m_activeUsers.insert(std::make_pair(user,new DirectoryController(user->getRootNode())));
                sendEvent(user,A_Login,UP_User);
                return user;
            }
            else
                return nullptr; //??? - wrong password
        }
    }
    return nullptr; // ??? - user not found
}
User* UserController::logout(User* user){
    auto activeUserInfo = m_activeUsers.find(user);
    if (activeUserInfo!=m_activeUsers.end()) {
        delete activeUserInfo->second;
        m_activeUsers.erase(activeUserInfo);
        sendEvent(user,A_Logout,UP_User);
        return user;
    }
    else {
        return nullptr;
    }
}

bool UserController::remove(User* user){
    logout(user);
    auto userInfo = m_allUsers.find(user);
    if (userInfo!=m_allUsers.end()) {
        sendEvent(user,A_Delete,UP_User);
        delete user;
        m_allUsers.erase(userInfo);
        return true;
    }
    else {
        return false;
    }
}

User* UserController::changePassword(User* user, const std::string& password){
    std::string oldpassword = user->getPassword();
    user->setPassword(password);
    sendEvent(user,A_Update,UP_Password,oldpassword,password);
}

User* UserController::changeInfo(User* user, const std::string& firstName, const std::string& lastName){
    std::string oldFirstName = user->getFirstName();
    std::string oldLastName = user->getLastName();
    user->setFirstName(firstName);
    user->setLastName(lastName);
    sendEvent(user,A_Update,UP_FirstName,oldFirstName,firstName);
    sendEvent(user,A_Update,UP_LastName,oldLastName,lastName);
}

DirectoryController* UserController::controllerFor(User* user){
    auto activeUserInfo = m_activeUsers.find(user);
    if (activeUserInfo!=m_activeUsers.end()) {
        return activeUserInfo->second;
    }
    else {
        return nullptr;
    }
}

void UserController::addObserver (IUserObserver * observer){
    m_observers.insert(observer);
}
void UserController::removeObserver (IUserObserver * observer){
    m_observers.erase(observer);
}

void UserController::sendEvent(User* user,  Action action, UserProp up, const std::string& oldValue, const std::string& newValue){
    for (IUserObserver * observer : m_observers)  {
        observer->onUserChanged(user,action,up,oldValue,newValue);
    }
}

std::set<User*>::iterator UserController::findUser(User* user){
    return m_allUsers.find (user);
}

