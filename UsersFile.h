#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>
#include <cstdlib>

#include "User.h"
#include "CMarkup/Markup.h"

using namespace std;

class UsersFile {
    const string USERS_FILE_NAME;

public:
    UsersFile(string usersFileName) : USERS_FILE_NAME(usersFileName) {};
    void saveUserToFile(User user);
    vector <User> loadUsersFromFile();
};

#endif
