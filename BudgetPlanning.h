#ifndef BUDGETPLANNING_H
#define BUDGETPLANNING_H

#include <iostream>
#include <windows.h>

#include "UserManager.h"
#include "FinanceManager.h"

using namespace std;

class BudgetPlanning {
    UserManager userManager;
    FinanceManager *financeManager;

public:
    BudgetPlanning(string usersFileName) : userManager(usersFileName) {};
    ~BudgetPlanning() {
        delete financeManager;
    }
    void registerUser();
    void logOnUser();
    void logOutUser();
    void changePassword();
    void displayStartMenu();
    void displayLoggedUserMenu();
    void displayUsers(); //development only
};

#endif
