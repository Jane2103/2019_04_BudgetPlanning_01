#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income {
    int incomeId;
    int userId;
    int date;
    string item;
    float amount;

public:
    void setIncomeId(int incomeId);
    void setUserId(int userId);
    void setDate(int date);
    void setItem(string item);
    void setAmount(float amount);

    int getIncomeId();
    int getUserId();
    int getDate();
    string getItem();
    float getAmount();
};

#endif
