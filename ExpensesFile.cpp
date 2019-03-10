#include "ExpensesFile.h"

vector <Expense> ExpensesFile::loadExpensesFromFile(int loggedUserId) {
    Expense espense;
    vector <Expense> espenses;

    xml.Load(EXPENSES_FILE_NAME.c_str());

    bool idCorrect;
    lastExpenseId = 0;
    while (xml.FindElem("expenseId")) {
        cout << "yes" << endl;
        lastExpenseId = atoi(xml.GetData().c_str());
        espense.setExpenseId(lastExpenseId);

        xml.FindElem("userId");
        espense.setUserId(atoi(xml.GetData().c_str()));

        if (loggedUserId == atoi(xml.GetData().c_str()))
            idCorrect = true;
        else
            idCorrect = false;

        xml.FindElem("date");
        espense.setDate(atoi(xml.GetData().c_str()));

        xml.FindElem("item");
        espense.setItem(xml.GetData());

        xml.FindElem("amount");
        espense.setAmount(atof(xml.GetData().c_str()));

        if (idCorrect)
            espenses.push_back(espense);
    }
    return espenses;
}

int ExpensesFile::getLastExpenseId() {
    return lastExpenseId;
}

void ExpensesFile::saveExpenseIntoFile(Expense expense) {
    CMarkup xml;

    xml.Load(EXPENSES_FILE_NAME.c_str());

    xml.AddElem("expenseId", expense.getExpenseId());
    xml.AddElem("userId", expense.getUserId());
    xml.AddElem("date", expense.getDate());
    xml.AddElem("item", expense.getItem());
    xml.AddElem("amount", AuxiliaryMethods::convertFloatToStr(expense.getAmount()));

    lastExpenseId++;

    xml.Save(EXPENSES_FILE_NAME.c_str());
}

/*string ExpensesFile::convertFloatToStr(float numberToConvert) {
    stringstream floatToStr;
    string str;
    floatToStr << numberToConvert;
    floatToStr >> str;
    floatToStr.clear();
    return str;
}*/
