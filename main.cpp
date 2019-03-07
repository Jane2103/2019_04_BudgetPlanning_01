#include <iostream>

#include "BudgetPlanning.h"

using namespace std;

int main() {
    BudgetPlanning budgetPlanning("users.xml", "incomes.xml", "expenses.xml");
    budgetPlanning.displayStartMenu();
    //budgetPlanning.displayUsers();

    return 0;
}
