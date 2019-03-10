#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib> //development only
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
    //string a, b; //development only


public:
    FinanceManager(string incomesFileName, string expensesFileName, int loggedUserId) :
        incomesFile(incomesFileName), expensesFile(expensesFileName), LOGGED_USER_ID(loggedUserId) {
        incomes = incomesFile.loadIncomesFromFile(LOGGED_USER_ID);
        expenses = expensesFile.loadExpensesFromFile(LOGGED_USER_ID);

    };
    void addIncome();
    void addExpense();
    void displayIncomes(int startDate, int endDate); //development only
    //void displayExpenses();
    Income provideIncomeDetails();
    Expense provideExpenseDetails();
    bool amountCorrect(float amount);
    string convertFloatToStr(float numberToConvert); //development only
    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    string convertDateToValidDateFormat(int dateAsInteger);
    string intToStr(int number);
    void displayExpenses(int startDate, int endDate);
    void displayCustomPeriodBalance();
};



#endif
