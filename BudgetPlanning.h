#ifndef BUDGETPLANNING_H
#define BUDGETPLANNING_H

#include <iostream>
#include <windows.h>

#include "UserManager.h"

using namespace std;

class BudgetPlanning {
    UserManager userManager;

public:
    BudgetPlanning(string usersFileName) : userManager(usersFileName) {};
    void registerUser();
    void logOnUser();
    void logOutUser();
    void changePassword();
    void displayStartMenu();
    void displayUsers(); //development only
};

#endif
