#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <vector>

#include "CMarkup/Markup.h"
#include "Income.h"

using namespace std;

class IncomesFile {
    const string INCOMES_FILE_NAME;
    int lastIncomeId;

public:
    IncomesFile(string incomesFileName) : INCOMES_FILE_NAME(incomesFileName) {};
    vector <Income> loadIncomesFromFile(int loggedUserId);
    int getLastIncomeId();
};

#endif
