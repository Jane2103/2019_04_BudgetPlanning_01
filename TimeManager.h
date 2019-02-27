#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include <iostream>
#include <time.h>
#include <cstdlib>

#define DATE_FORMAT_SIZE 11

using namespace std;

class TimeManager {
    time_t rawTime;
    tm *timeInfo;
    char yyyy_mm_dd_Date[DATE_FORMAT_SIZE];

public:
    string getActualDateAsString(); // string yyyy-mm-dd
    int year(string dateAsString);
    int month(string dateAsString);
    int day(string dateAsString);
    bool dayCorrect(string dateAsString);
    int getDateAsInteger(string dateAsString);
};

#endif
