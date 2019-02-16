#include <iostream>

#include "BudgetPlanning.h"

using namespace std;

int main() {
    BudgetPlanning budgetPlanning("users.xml");
    budgetPlanning.displayStartMenu();
    //budgetPlanning.displayUsers();

    return 0;
}
