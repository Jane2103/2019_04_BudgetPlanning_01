#include "ExpensesFile.h"

vector <Expense> ExpensesFile::loadExpensesFromFile(int loggedUserId) {
    Expense espense;
    vector <Expense> espenses;
    CMarkup xml;

    //bool xmlOpen = xml.Load(INCOMES_FILE_NAME.c_str());
    xml.Load(EXPENSES_FILE_NAME.c_str());

    //cout << INCOMES_FILE_NAME << endl;
    //system("pause");


    bool idCorrect;
    lastExpenseId = 0;
    while (xml.FindElem("expenseId")) {
        cout << "yes" << endl;
        lastExpenseId = atoi(xml.GetData().c_str());
        /*cout << "Last income id: " << lastIncomeId << endl;
        system("pause");*/
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
        espense.setAmount(atof(xml.GetData().c_str())); //is that function (atoi) proper for float data type? TBD

        if (idCorrect)
            espenses.push_back(espense);
    }
    /*if (incomes.empty())
        cout << "No incomes for logged user" << endl;*/
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
    xml.AddElem("amount", convertFloatToStr(expense.getAmount()));

    lastExpenseId++;

    xml.Save(EXPENSES_FILE_NAME.c_str());
}

string ExpensesFile::convertFloatToStr(float numberToConvert) {
    stringstream floatToStr;
    string str;
    floatToStr << numberToConvert;
    floatToStr >> str;
    floatToStr.clear();
    return str;
}
