#include "IncomesFile.h"

vector <Income> IncomesFile::loadIncomesFromFile(int loggedUserId) {
    Income income;
    vector <Income> incomes;
    CMarkup xml;

    //bool xmlOpen = xml.Load(INCOMES_FILE_NAME.c_str());
    xml.Load(INCOMES_FILE_NAME.c_str());

    //cout << INCOMES_FILE_NAME << endl;
    //system("pause");


    bool idCorrect;
    lastIncomeId = 0;
    while (xml.FindElem("incomeId")) {
        cout << "yes" << endl;
        lastIncomeId = atoi(xml.GetData().c_str());
        /*cout << "Last income id: " << lastIncomeId << endl;
        system("pause");*/
        income.setIncomeId(lastIncomeId);


        xml.FindElem("userId");
        income.setUserId(atoi(xml.GetData().c_str()));

        if (loggedUserId == atoi(xml.GetData().c_str()))
            idCorrect = true;
        else
            idCorrect = false;

        xml.FindElem("date");
        income.setDate(atoi(xml.GetData().c_str()));

        xml.FindElem("item");
        income.setItem(xml.GetData());

        xml.FindElem("amount");
        income.setAmount(atof(xml.GetData().c_str())); //is that function (atoi) proper for float data type? TBD

        if (idCorrect)
            incomes.push_back(income);
    }
    /*if (incomes.empty())
        cout << "No incomes for logged user" << endl;*/
    return incomes;
}

int IncomesFile::getLastIncomeId() {
    return lastIncomeId;
}

void IncomesFile::saveIncomeIntoFile(Income income) {
    CMarkup xml;

    xml.Load(INCOMES_FILE_NAME.c_str());

    xml.AddElem("incomeId", income.getIncomeId());
    xml.AddElem("userId", income.getUserId());
    xml.AddElem("date", income.getDate());
    xml.AddElem("item", income.getItem());
    xml.AddElem("amount", AuxiliaryMethods::convertFloatToStr(income.getAmount()));

    lastIncomeId++;

    xml.Save(INCOMES_FILE_NAME.c_str());
}
