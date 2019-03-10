#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense {
    int expenseId;
    int userId;
    int date;
    string item;
    float amount;

public:
    void setExpenseId(int expenseId);
    void setUserId(int userId);
    void setDate(int date);
    void setItem(string item);
    void setAmount(float amount);

    int getExpenseId();
    int getUserId();
    int getDate();
    string getItem();
    float getAmount();

    //code below enables to sort Incomes by date
    bool operator < (const Expense &exp) const {
        return (date < exp.date);
    }

};

#endif
