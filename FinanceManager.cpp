#include "FinanceManager.h"

void FinanceManager::addIncome() {
    Income income = provideIncomeDetails();
    incomes.push_back(income);
    incomesFile.saveIncomeIntoFile(income);

    cout << endl << "Income added" << endl << endl;
    system("pause");
}

void FinanceManager::addExpense() {
    Expense expense = provideExpenseDetails();
    expenses.push_back(expense);
    expensesFile.saveExpenseIntoFile(expense);

    cout << endl << "Expense added" << endl << endl;
    system("pause");
}

void FinanceManager::displayIncomes() {

    if (!incomes.empty()) {
        vector <Income> :: iterator it;
        for (it = incomes.begin(); it != incomes.end(); it++) {
            cout << it -> getItem() << endl;
            cout << it -> getAmount() << endl;
        }
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
    string amountToConvert;
    string comma = ",";
    string point = ".";
    int commaIndex;
    float amountConverted;
    //float amount;
    char selectOption;

    income.setUserId(LOGGED_USER_ID);
    /*cout << "Last income id: " << incomesFile.getLastIncomeId() << endl;
    system("pause");*/
    income.setIncomeId(incomesFile.getLastIncomeId() + 1);

    //cout << incomesFile.getLastIncomeId() + 1 << endl; // development only

    cout << "Enter item: ";
    cin >> item;
    income.setItem(item);

    /*cout << "Enter date: ";
    cin >> dateToConvert;
    dateConverted = atoi(dateToConvert.c_str());
    income.setDate(dateConverted);*/

    cout << "With what date do you want to post the income?" << endl;
    cout << "(1) Actual date" << endl;
    cout << "(2) Custom date" << endl;
    cout << "Select option: ";
    cin >> selectOption;

    switch (selectOption) {
    case '1':
        dateToConvert = timeManager.getActualDateAsString();
        dateConverted = timeManager.getDateAsInteger(dateToConvert);
        income.setDate(dateConverted);
        break;
    case '2':
        do {
            cout << "Enter date (yyyy-mm-dd):";
            cin >> dateToConvert;


            if (timeManager.dayCorrect(dateToConvert) == false || timeManager.dateFormatValid(dateToConvert) == false)
                cout << "Incorrect date" << endl;

        } while (timeManager.dayCorrect(dateToConvert) == false || timeManager.dateFormatValid(dateToConvert) == false);

        dateConverted = timeManager.getDateAsInteger(dateToConvert);
        income.setDate(dateConverted);
        break;
    }

    /*do {
        cout << "Enter amount (PLN): ";
        cin >> amount;

        if (!amountCorrect(amount))
            cout << "Amount must be positive value" << endl;
    } while (!amountCorrect(amount));*/

    do {
        cout << "Enter amount (PLN): ";
        cin >> amountToConvert;

        commaIndex = amountToConvert.find(comma);
        if (commaIndex > 0)
            amountToConvert.replace(commaIndex, 1, point);

        amountConverted = atof(amountToConvert.c_str());
        /*cout << amountConverted << endl;
        system("pause");*/

        if (!amountCorrect(amountConverted))
            cout << "Amount must be positive value" << endl;

    } while (!amountCorrect(amountConverted));



    //income.setAmount(amount);
    income.setAmount(amountConverted);

    return income;
}

Expense FinanceManager::provideExpenseDetails() {
    Expense expense;
    string dateToConvert;
    int dateConverted;
    string item;
    string amountToConvert;
    string comma = ",";
    string point = ".";
    int commaIndex;
    float amountConverted;
    //float amount;
    char selectOption;

    expense.setUserId(LOGGED_USER_ID);
    expense.setExpenseId(expensesFile.getLastExpenseId() + 1);

    cout << "Enter item: ";
    cin >> item;
    expense.setItem(item);

    cout << "With what date do you want to post the income?" << endl;
    cout << "(1) Actual date" << endl;
    cout << "(2) Custom date" << endl;
    cout << "Select option: ";
    cin >> selectOption;

    switch (selectOption) {
    case '1':
        dateToConvert = timeManager.getActualDateAsString();
        dateConverted = timeManager.getDateAsInteger(dateToConvert);
        expense.setDate(dateConverted);
        break;
    case '2':
        do {
            cout << "Enter date (yyyy-mm-dd):";
            cin >> dateToConvert;


            if (timeManager.dayCorrect(dateToConvert) == false || timeManager.dateFormatValid(dateToConvert) == false)
                cout << "Incorrect date" << endl;

        } while (timeManager.dayCorrect(dateToConvert) == false || timeManager.dateFormatValid(dateToConvert) == false);

        dateConverted = timeManager.getDateAsInteger(dateToConvert);
        expense.setDate(dateConverted);
        break;
    }

    do {
        cout << "Enter amount (PLN): ";
        cin >> amountToConvert;

        commaIndex = amountToConvert.find(comma);
        if (commaIndex > 0)
            amountToConvert.replace(commaIndex, 1, point);

        amountConverted = atof(amountToConvert.c_str());
        /*cout << amountConverted << endl;
        system("pause");*/

        if (!amountCorrect(amountConverted))
            cout << "Amount must be positive value" << endl;

    } while (!amountCorrect(amountConverted));

    expense.setAmount(amountConverted);

    return expense;
}

bool FinanceManager::amountCorrect(float amount) {
    if (amount <= 0)
        return false;
    else
        return true;
}

string FinanceManager::convertFloatToStr(float numberToConvert) {
    stringstream floatToStr;
    string str;
    floatToStr << numberToConvert;
    floatToStr >> str;
    floatToStr.clear();
    return str;
} //development only
