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
            //logOnUser();
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

void BudgetPlanning::displayUsers() {
    userManager.displayUsers();
}
