#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <iostream>
#include <vector>
#include <time.h>

#include "Income.h"
#include "Expense.h"
#include "IncomesFile.h"
#include "ExpensesFile.h"
#include "TimeManager.h"

using namespace std;

class FinanceManager {
    vector <Income> incomes;
    IncomesFile incomesFile;

    vector <Expense> expenses;
    ExpensesFile expensesFile;

    const int LOGGED_USER_ID;
    TimeManager timeManager;
    //string a, b; //development only


public:
    FinanceManager(string incomesFileName, string expensesFileName, int loggedUserId) :
        incomesFile(incomesFileName), expensesFile(expensesFileName), LOGGED_USER_ID(loggedUserId) {
        incomes = incomesFile.loadIncomesFromFile(LOGGED_USER_ID);

    };
    void addIncome();
    void displayIncomes(); //development only
    Income provideIncomeDetails();
    bool amountCorrect(int amount);
};

#endif
