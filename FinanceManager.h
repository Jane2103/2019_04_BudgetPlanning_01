#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <iostream>
#include <vector>
//#include <time.h>
//#include <cstdlib> //development only
#include <algorithm>

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

    void displayIncomes(int startDate, int endDate);
    Income provideIncomeDetails();
    Expense provideExpenseDetails();
    bool amountCorrect(float amount);
    void displayBalance(int startDate, int endDate);
    float enterAmount();
    int enterDate();

public:
    FinanceManager(string incomesFileName, string expensesFileName, int loggedUserId) :
        incomesFile(incomesFileName), expensesFile(expensesFileName), LOGGED_USER_ID(loggedUserId) {
        incomes = incomesFile.loadIncomesFromFile(LOGGED_USER_ID);
        expenses = expensesFile.loadExpensesFromFile(LOGGED_USER_ID);

    };
    void addIncome();
    void addExpense();
    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    void displayExpenses(int startDate, int endDate);
    void displayCustomPeriodBalance();
};



#endif
