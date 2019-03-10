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
                cout << "Item: " << it -> getItem() << endl;
                cout << "Amount: " << it -> getAmount() << endl;
                cout << "Date: " << convertDateToValidDateFormat(it -> getDate()) << endl;
                cout << endl;
            }
        }
    } else
        cout << "No incomes" << endl;
    system("pause");
}

void FinanceManager::displayExpenses(int startDate, int endDate) {

    if (!expenses.empty()) {
        vector <Expense> :: iterator it;
        for (it = expenses.begin(); it != expenses.end(); it++) {
            if (it -> getDate() >= startDate && it -> getDate() <= endDate) {
                cout << "Item: " << it -> getItem() << endl;
                cout << "Amount: " << it -> getAmount() << endl;
                cout << "Date: " << convertDateToValidDateFormat(it -> getDate()) << endl;
                cout << endl;
            }
        }
    } else
        cout << "No expenses" << endl;
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



void FinanceManager::displayCurrentMonthBalance() {
    int endDate = timeManager.getDateAsInteger(timeManager.getActualDateAsString());
    //cout << "end date: " << endDate << endl;
    //system("pause");
    int startDate = timeManager.getDateAsInteger(timeManager.getActualDateAsString()) - timeManager.day(timeManager.getActualDateAsString()) + 1;
    //cout << "start date: " << startDate << endl;
    //system("pause");
    vector <Income> :: iterator iti;
    vector <Expense> :: iterator ite;

    sort(incomes.begin(), incomes.end());
    cout << "Incomes:" << endl;
    displayIncomes(startDate, endDate);
    cout << endl;

    sort(expenses.begin(), expenses.end());
    cout << "Expenses: " << endl;
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

    cout << "Sum of INCOMES: " << incomesSum << endl;
    cout << "Sum of EXPENSES: " << expensesSum << endl;
    cout << "Balance: " << incomesSum - expensesSum << endl;

    system("pause");

}

void FinanceManager::displayPreviousMonthBalance() {
    int startDate = timeManager.startDateOfPreviousMonth();
    int endDate = timeManager.endDateOfPreviousMonth();

    sort(incomes.begin(), incomes.end());
    cout << "Incomes:" << endl;
    displayIncomes(startDate, endDate);
    cout << endl;

    sort(expenses.begin(), expenses.end());
    cout << "Expenses: " << endl;
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

    cout << "Sum of INCOMES: " << incomesSum << endl;
    cout << "Sum of EXPENSES: " << expensesSum << endl;
    cout << "Balance: " << incomesSum - expensesSum << endl;

    system("pause");
}

string FinanceManager::intToStr(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string FinanceManager::convertDateToValidDateFormat(int dateAsInteger) {
    //string rawDateFormat = intToStr(dateAsInteger);
    string pause = "-";
    string yyyy_mm_dd_dateFormat = intToStr(dateAsInteger);
    int firstPauseIndex = 4;
    int secondPauseIndex = 7;
    yyyy_mm_dd_dateFormat.insert(firstPauseIndex, pause);
    yyyy_mm_dd_dateFormat.insert(secondPauseIndex, pause);
    return yyyy_mm_dd_dateFormat;
}

void FinanceManager::displayCustomPeriodBalance() {
    string startDate;
    string endDate;
    int startDateConverted;
    int endDateConverted;

    do {
        do {
            cout << "Enter start date (yyyy-mm-dd):";
            cin >> startDate;


            if (timeManager.dayCorrect(startDate) == false || timeManager.dateFormatValid(startDate) == false)
                cout << "Incorrect date" << endl;

        } while (timeManager.dayCorrect(startDate) == false || timeManager.dateFormatValid(startDate) == false);

        do {
            cout << "Enter end date (yyyy-mm-dd):";
            cin >> endDate;


            if (timeManager.dayCorrect(endDate) == false || timeManager.dateFormatValid(endDate) == false)
                cout << "Incorrect date" << endl;

        } while (timeManager.dayCorrect(endDate) == false || timeManager.dateFormatValid(endDate) == false);

        startDateConverted = timeManager.getDateAsInteger(startDate);
        endDateConverted = timeManager.getDateAsInteger(endDate);

        if (startDateConverted > endDateConverted)
            cout << "Start date must be defined as earlier than end date" << endl;
    } while (startDateConverted > endDateConverted);

    sort(incomes.begin(), incomes.end());
    cout << "Incomes:" << endl;
    displayIncomes(startDateConverted, endDateConverted);
    cout << endl;

    sort(expenses.begin(), expenses.end());
    cout << "Expenses: " << endl;
    displayExpenses(startDateConverted, endDateConverted);
    cout << endl;

    float incomesSum = 0.0;
    int incomesSize = incomes.size();
    for (int i = 0; i < incomesSize; i++) {
        if (incomes[i].getDate() >= startDateConverted && incomes[i].getDate() <= endDateConverted)
            incomesSum += incomes[i].getAmount();
    }

    float expensesSum = 0.0;
    int expensesSize = expenses.size();
    for (int i = 0; i < expensesSize; i++) {
        if (expenses[i].getDate() >= startDateConverted && expenses[i].getDate() <= endDateConverted)
            expensesSum += expenses[i].getAmount();
    }

    cout << "Sum of INCOMES: " << incomesSum << endl;
    cout << "Sum of EXPENSES: " << expensesSum << endl;
    cout << "Balance: " << incomesSum - expensesSum << endl;

    system("pause");

}
