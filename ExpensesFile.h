#ifndef EXPENSES_H
#define EXPENSES_H

#include <iostream>
#include <vector>
#include <sstream>

#include "CMarkup/Markup.h"
#include "Expense.h"
#include "AuxiliaryMethods.h"


using namespace std;

class ExpensesFile {
    const string EXPENSES_FILE_NAME;
    int lastExpenseId;
    CMarkup xml;

public:
    ExpensesFile(string expensesFileName) : EXPENSES_FILE_NAME(expensesFileName) {};
    vector <Expense> loadExpensesFromFile(int loggedUserId);
    int getLastExpenseId();
    void saveExpenseIntoFile(Expense expense);
    //string convertFloatToStr(float numberToConvert);
};

#endif
