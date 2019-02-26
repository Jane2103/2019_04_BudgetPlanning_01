#include "FinanceManager.h"

void FinanceManager::addIncome() {
    Income income = provideIncomeDetails();
    incomes.push_back(income);
    incomesFile.saveIncomeIntoFile(income);

    cout << endl << "Income added" << endl << endl;
    system("pause");
}

void FinanceManager::displayIncomes() {

    if (!incomes.empty()) {
        vector <Income> :: iterator it;
        for (it = incomes.begin(); it != incomes.end(); it++)
            cout << it -> getItem() << endl;
    }
    else
        cout << "No incomes" << endl;
    system("pause");

}

Income FinanceManager::provideIncomeDetails() {
    Income income;
    string dateToConvert;
    int dateConverted;
    string item;
    float amount;

    income.setUserId(LOGGED_USER_ID);
    income.setIncomeId(incomesFile.getLastIncomeId() + 1);

    //cout << incomesFile.getLastIncomeId() + 1 << endl; // development only

    cout << "Enter item: ";
    cin >> item;
    income.setItem(item);

    cout << "Enter date: ";
    cin >> dateToConvert;
    dateConverted = atoi(dateToConvert.c_str());
    income.setDate(dateConverted);

    cout << "Enter amount (PLN): ";
    cin >> amount;
    income.setAmount(amount);

    return income;
}
