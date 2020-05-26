#include "IUserObserver.h"


class UserView : public IUserObserver
{
    public:
        /** Default constructor */
        UserView();
        virtual void onUserChanged (User* user,  Action action, UserProp up, const std::string& oldValue, const std::string& newValue) override;

        void printUser(User* user);

    protected:

    private:
};
