#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "User.h"
#include "UsersFile.h"

using namespace std;

class UserManager {
    int loggedUserId;
    string loggedUserName;
    string loggedUserSurname;
    vector <User> users;
    UsersFile usersFile;

    User setNewUserData();
    int getNewUserId();
    bool userLoginExists(string login);
public:
    UserManager(string usersFileName) : usersFile(usersFileName) {
        users = usersFile.loadUsersFromFile();
    };
    void registerUser();
    void logOnUser();
    void logOutUser();
    bool userLoggedIn();
    int getLoggedUserId();
    void changePassword();
    void displayUsers(); //development only
    bool userLogged();
    string getUserName();
    string getUserSurname();

};

#endif
