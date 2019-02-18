#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <iostream>
#include <vector>

#include "Income.h"
#include "Expense.h"

using namespace std;

class FinanceManager {
    vector <Income> incomes;
    vector <Expense> expenses;
    const int LOGGED_USER_ID;
    string a, b; //development only

public:
    FinanceManager(string incomesFileName, string expensesFileName, int loggedUserId) :
        a(incomesFileName), b(expensesFileName), LOGGED_USER_ID(loggedUserId) {};
};

#endif
