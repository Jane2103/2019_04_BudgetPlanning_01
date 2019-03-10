#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <sstream>

#include "AuxiliaryMethods.h"

#define DATE_FORMAT_SIZE 11
#define JANUARY 1
#define AUGUST 8
#define OCTOBER 10
#define DECEMBER 12

using namespace std;

class TimeManager {
    time_t rawTime;
    tm *timeInfo;
    char yyyy_mm_dd_Date[DATE_FORMAT_SIZE];

    int pauseASCIICode; // = 45;
    int zeroASCIICode; // = 48;
    int nineASCIICode; // = 57;

    void copyDate(string dateAsString);
    bool separationMarkValid(string &dateToConvert);
    bool leapYear(int year);
    bool yearValid(string &dateToConvert);
    bool monthValid(string &dateToConvert);
    bool dayValid(string &dateToConvert);

public:
    TimeManager();
    string getActualDateAsString();
    int year(string dateAsString);
    int month(string dateAsString);
    int day(string dateAsString);
    bool dayCorrect(string dateAsString);
    int getDateAsInteger(string dateAsString);
    bool dateFormatValid(string dateToConvert);
    int countDaysOfMonth(int numberOfMonth, int year);
    int startDateOfPreviousMonth();
    int endDateOfPreviousMonth();
    string convertDateToValidDateFormat(int dateAsInteger);
};

#endif
