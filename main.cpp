#include <iostream>

#include "Document.hpp"
#include "Directory.hpp"
#include "User.hpp"
#include "UserController.hpp"
#include "UserView.hpp"

using namespace std;

int main()
{

    UserController * uc = new UserController();

    UserView * uv = new UserView();

    uc->addObserver (uv);

    uc->createUser("ivan","qwerty","Ivan","Ivanov");
    uc->createUser("petr","qwerty","Petro","Petrenko");
    User* user = uc->login("ivan","qwerty");
    if (user)
    {
        cout <<"Hello, I am Ivanov, and I can work!" <<endl;
        uc->changeInfo(user,"Vanya","Ivanov");
        if (uc->logout(user))
        {
            cout <<"Ivanov log out!" <<endl;
            uc->remove(user);
        }
    }

    /*cout << "Hello world!" << endl;

    Directory* testDir = new Directory("testDir");
    cout <<"Is directory empty: " <<boolalpha <<testDir->hasChildren() <<endl;

    Document* testDoc = new Document ("testDoc", "blue");
    testDir->addChild(testDoc);
    cout <<"Is directory empty: " <<boolalpha <<testDir->hasChildren() <<endl;

    delete testDir;*/

    return 0;
}
