#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <sstream>

#include "AuxiliaryMethods.h"

#define DATE_FORMAT_SIZE 11


using namespace std;



class TimeManager {
    time_t rawTime;
    tm *timeInfo;
    char yyyy_mm_dd_Date[DATE_FORMAT_SIZE];

    int pauseASCIICode;// = 45;
    int zeroASCIICode;// = 48;
    int nineASCIICode;// = 57;

public:
    TimeManager();
    string getActualDateAsString(); // string yyyy-mm-dd
    int year(string dateAsString);
    int month(string dateAsString);
    int day(string dateAsString);
    bool dayCorrect(string dateAsString);
    int getDateAsInteger(string dateAsString);
    void copyDate(string dateAsString);
    bool dateFormatValid(string dateToConvert);
    bool yearValid(string &dateToConvert);
    bool monthValid(string &dateToConvert);
    bool dayValid(string &dateToConvert);
    bool separationMarkValid(string &dateToConvert);
    int countDaysOfMonth(int numberOfMonth, int year);
    bool leapYear(int year);
    int startDateOfPreviousMonth();
    int endDateOfPreviousMonth();
    //string intToStr(int number);
    string convertDateToValidDateFormat(int dateAsInteger);
};

#endif
