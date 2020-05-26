#pragma once

enum NodeType {
    NT_Directory = 0,
    NT_Document = 1
};

enum UserProp {
    UP_Nickname,
    UP_FirstName,
    UP_LastName,
    UP_Password,
    UP_User
};

enum Action {
    A_Create,
    A_Update,
    A_Delete,
    A_Login,
    A_Logout
};

//#ifndef DMENUMS_H_INCLUDED
//#define DMENUMS_H_INCLUDED
//#endif // DMENUMS_H_INCLUDED
