#include "BudgetPlanning.h"

void BudgetPlanning::displayStartMenu() {
    char userChoice;

    while (true) {
        system("cls");

        cout << "\tMAIN MENU" << endl;
        cout << "------------------------------" << endl;
        cout << "(1) Login user" << endl;
        cout << "(2) Register user" << endl;
        cout << "(3) Exit" << endl;
        cout << "------------------------------" << endl;

        cout << "Select: ";
        cin >> userChoice;

        cout << "------------------------------" << endl;

        switch (userChoice) {
        case '1':
            logOnUser();
            break;
        case '2':
            registerUser();
            break;
        case '3':
            exit(0);
        }
    }
}

void BudgetPlanning::registerUser() {
    userManager.registerUser();
}

void BudgetPlanning::displayLoggedUserMenu() {
    char userChoice;
    system("cls");

    cout << "Logged user: " << userManager.getUserName() << " " << userManager.getUserSurname() << endl;

    cout << "------------------------------" << endl;
    cout << "(1) Add income" << endl;
    cout << "(2) Add expense" << endl;
    cout << "(3) Current month balance" << endl;
    cout << "(4) Previous month balance" << endl;
    cout << "(5) Custom period balance" << endl;
    cout << "(6) Change password" << endl;
    cout << "(7) Log out" << endl;
    cout << "------------------------------" << endl;

    cout << "Select: ";
    cin >> userChoice;

    cout << "------------------------------" << endl;

    switch (userChoice) {
    case '1':
        financeManager -> addIncome();
        break;
    case '2':
        financeManager -> addExpense();
        break;
    case '3':
        financeManager -> displayCurrentMonthBalance();
        break;
    case '4':
        financeManager -> displayPreviousMonthBalance();
        break;
    case '5':
        financeManager -> displayCustomPeriodBalance();
        break;
    case '6':
        userManager.changePassword();
        break;
    case '7':
        logOutUser();
        break;
    }
}

void BudgetPlanning::logOnUser() {
    userManager.logOnUser();
    if (userManager.userLogged()) {
        financeManager = new FinanceManager(INCOMES_FILE_NAME, EXPENSES_FILE_NAME, userManager.getLoggedUserId());
        while (userManager.userLogged())
            displayLoggedUserMenu();
    }
    else
        system("cls");
}

void BudgetPlanning::logOutUser() {
    userManager.logOutUser();
    cout << "User has been logged out" << endl << endl;
    system("pause");
    displayStartMenu();
    delete financeManager;
}
