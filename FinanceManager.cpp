#include "FinanceManager.h"

void FinanceManager::addIncome() {



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
