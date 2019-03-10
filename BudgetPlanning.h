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
    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;

public:
    BudgetPlanning(string usersFileName, string incomesFileName, string expensesFileName)
        : userManager(usersFileName),  INCOMES_FILE_NAME(incomesFileName), EXPENSES_FILE_NAME(expensesFileName) {};
    ~BudgetPlanning() {
        delete financeManager;
    }
    void registerUser();
    void logOnUser();
    void logOutUser();
    void changePassword();
    void displayStartMenu();
    void displayLoggedUserMenu();
};

#endif
