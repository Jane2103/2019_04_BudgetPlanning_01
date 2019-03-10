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

void FinanceManager::displayIncomes(int startDate, int endDate) {

    if (!incomes.empty()) {
        vector <Income> :: iterator it;
        for (it = incomes.begin(); it != incomes.end(); it++) {
            if (it -> getDate() >= startDate && it -> getDate() <= endDate) {
                cout << "Item:  \t " << it -> getItem() << endl;
                cout << "Amount:\t " << it -> getAmount() << endl;
                cout << "Date:  \t " << timeManager.convertDateToValidDateFormat(it -> getDate()) << endl;
                cout << endl;
            }
        }
    } else
        cout << "No incomes" << endl;
}

void FinanceManager::displayExpenses(int startDate, int endDate) {

    if (!expenses.empty()) {
        vector <Expense> :: iterator it;
        for (it = expenses.begin(); it != expenses.end(); it++) {
            if (it -> getDate() >= startDate && it -> getDate() <= endDate) {
                cout << "Item:  \t " << it -> getItem() << endl;
                cout << "Amount:\t " << it -> getAmount() << endl;
                cout << "Date:  \t " << timeManager.convertDateToValidDateFormat(it -> getDate()) << endl;
                cout << endl;
            }
        }
    } else
        cout << "No expenses" << endl;
}

Income FinanceManager::provideIncomeDetails() {
    Income income;
    string dateToConvert;
    int dateConverted;
    string item;
    float amountConverted;
    char selectOption;

    income.setUserId(LOGGED_USER_ID);

    income.setIncomeId(incomesFile.getLastIncomeId() + 1);

    cout << "Enter item: ";
    cin >> item;
    income.setItem(item);

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
        dateConverted = enterDate();
        income.setDate(dateConverted);
        break;
    }

    amountConverted = enterAmount();

    income.setAmount(amountConverted);

    return income;
}

int FinanceManager::enterDate() {
    string dateToConvert;
    do {
        cout << "Enter date (yyyy-mm-dd):";
        cin >> dateToConvert;

        if (timeManager.dayCorrect(dateToConvert) == false || timeManager.dateFormatValid(dateToConvert) == false)
            cout << "Incorrect date" << endl;

    } while (timeManager.dayCorrect(dateToConvert) == false || timeManager.dateFormatValid(dateToConvert) == false);

    return timeManager.getDateAsInteger(dateToConvert);
}

Expense FinanceManager::provideExpenseDetails() {
    Expense expense;
    string dateToConvert;
    int dateConverted;
    string item;
    float amountConverted;
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
        dateConverted = enterDate();
        expense.setDate(dateConverted);
        break;
    }

    amountConverted = enterAmount();

    expense.setAmount(amountConverted);

    return expense;
}

float FinanceManager::enterAmount() {
    string amountToConvert;
    string comma = ",";
    string point = ".";
    int commaIndex;
    float amountConverted;
    do {
        cout << "Enter amount (PLN): ";
        cin >> amountToConvert;

        commaIndex = amountToConvert.find(comma);
        if (commaIndex > 0)
            amountToConvert.replace(commaIndex, 1, point);

        amountConverted = atof(amountToConvert.c_str());

        if (!amountCorrect(amountConverted))
            cout << "Amount must be positive value" << endl;

    } while (!amountCorrect(amountConverted));

    return amountConverted;
}

bool FinanceManager::amountCorrect(float amount) {
    if (amount <= 0)
        return false;
    else
        return true;
}

void FinanceManager::displayCurrentMonthBalance() {
    int endDate = timeManager.getDateAsInteger(timeManager.getActualDateAsString());
    int startDate = timeManager.getDateAsInteger(timeManager.getActualDateAsString()) - timeManager.day(timeManager.getActualDateAsString()) + 1;

    displayBalance(startDate, endDate);
}

void FinanceManager::displayPreviousMonthBalance() {
    int startDate = timeManager.startDateOfPreviousMonth();
    int endDate = timeManager.endDateOfPreviousMonth();

    displayBalance(startDate, endDate);
}

void FinanceManager::displayCustomPeriodBalance() {
    int startDate;
    int endDate;

    do {
        cout << "From..." << endl;
        startDate = enterDate();

        cout << "... to:" << endl;
        endDate = enterDate();

        if (startDate > endDate)
            cout << "Start date must be defined as earlier than end date" << endl;
    } while (startDate > endDate);
    cout << endl;
    displayBalance(startDate, endDate);
}

void FinanceManager::displayBalance(int startDate, int endDate) {
    sort(incomes.begin(), incomes.end());
    cout << "------------------------------" << endl;
    cout << "Incomes:" << endl;
    cout << "------------------------------" << endl;
    displayIncomes(startDate, endDate);
    cout << endl;

    sort(expenses.begin(), expenses.end());
    cout << "------------------------------" << endl;
    cout << "Expenses: " << endl;
    cout << "------------------------------" << endl;
    displayExpenses(startDate, endDate);
    cout << endl;

    float incomesSum = 0.0;
    int incomesSize = incomes.size();
    for (int i = 0; i < incomesSize; i++) {
        if (incomes[i].getDate() >= startDate && incomes[i].getDate() <= endDate)
            incomesSum += incomes[i].getAmount();
    }

    float expensesSum = 0.0;
    int expensesSize = expenses.size();
    for (int i = 0; i < expensesSize; i++) {
        if (expenses[i].getDate() >= startDate && expenses[i].getDate() <= endDate)
            expensesSum += expenses[i].getAmount();
    }

    cout << "------------------------------" << endl;
    cout << "INCOMES: \t" << incomesSum << " PLN" << endl;
    cout << "EXPENSES:\t" << expensesSum << " PLN" << endl;
    cout << "------------------------------" << endl;
    cout << "BALANCE: \t" << incomesSum - expensesSum << " PLN" << endl;
    cout << "------------------------------" << endl << endl;

    system("pause");
}
