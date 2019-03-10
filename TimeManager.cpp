#include "TimeManager.h"

TimeManager::TimeManager() {
    pauseASCIICode = 45;// = 45;
    zeroASCIICode = 48;// = 48;
    nineASCIICode = 57;
}

string TimeManager::getActualDateAsString() {
    time(&rawTime);
    timeInfo = localtime(&rawTime);

    strftime(yyyy_mm_dd_Date, DATE_FORMAT_SIZE, "%Y-%m-%d", timeInfo);
    string actualDateAsString = yyyy_mm_dd_Date;

    return actualDateAsString;
}

void TimeManager::copyDate(string dateAsString) {
    int length = dateAsString.length();
    for (int i = 0; i < length; i++) {
        yyyy_mm_dd_Date[i] = dateAsString[i];
    }
}
int TimeManager::year(string dateAsString) {
    copyDate(dateAsString);
    string yearToConvert = "";
    for (int i = 0; i < 4; i++)
        yearToConvert += yyyy_mm_dd_Date[i];
    return atoi(yearToConvert.c_str());
}

int TimeManager::month(string dateAsString) {
    copyDate(dateAsString);
    string monthToConvert = "";
    for (int i = 5; i < 7; i++)
        monthToConvert += yyyy_mm_dd_Date[i];
    return atoi(monthToConvert.c_str());
}

int TimeManager::day(string dateAsString) {
    copyDate(dateAsString);
    string dayToConvert = "";
    for (int i = 8; i < DATE_FORMAT_SIZE; i++)
        dayToConvert += yyyy_mm_dd_Date[i];
    return atoi(dayToConvert.c_str());
}

//change function name to dateCorrect - TBD
bool TimeManager::dayCorrect(string dateAsString) {
    int minYear = 2000;
    int minMonth = 1;
    int minDay = 1;

    int providedYear, providedMonth, providedDay;
    int maxYear, maxMonth, maxDay;

    providedYear = year(dateAsString);
    /*cout << "Provided y: " << providedYear << endl;
    system("pause");*/
    providedMonth = month(dateAsString);
    //cout << "Provided m: " << providedMonth << endl;
    //system("pause");
    providedDay = day(dateAsString);
    //cout << "Provided d: " << providedDay << endl;
    //system("pause");

    maxYear = year(getActualDateAsString());
    //cout << "year: " << maxYear << endl;
    //system("pause");
    maxMonth = month(getActualDateAsString());
    //cout << "month: " << maxMonth << endl;
    //system("pause");
    maxDay = day(getActualDateAsString());
    //cout << "day: " << maxDay << endl;
    //system("pause");

    bool functionResult = false;

    if (providedYear >= minYear && providedYear <= maxYear) {
        if (providedYear < maxYear) {
            if (providedMonth >= minMonth && providedMonth <= 12
                && providedDay >= minDay && providedDay <= countDaysOfMonth(providedMonth, providedYear))
                    functionResult = true;
        } else if (providedYear == maxYear) {
            if (providedMonth < maxMonth && providedDay <= countDaysOfMonth(providedMonth, providedYear))
                functionResult = true;
            else if (providedMonth == maxMonth && providedDay <= maxDay)
                functionResult = true;
        }
    } else
        functionResult = false;

    return functionResult;
}

int TimeManager::getDateAsInteger(string dateAsString) {
    string dateToConvert = "";
    char pause = '-';
    for (int i = 0; i < DATE_FORMAT_SIZE; i++) {
        if (dateAsString[i] != pause)
            dateToConvert += dateAsString[i];
    }
    return atoi(dateToConvert.c_str());
}

bool TimeManager::dateFormatValid(string dateToConvert) {
    bool verificationTab[4];
    bool functionOutput;
    int stringLength = dateToConvert.length();
    if (stringLength == 10) {
        if (yearValid(dateToConvert))
            verificationTab[0] = true;
        if (monthValid(dateToConvert))
            verificationTab[1] = true;
        if (dayValid(dateToConvert))
            verificationTab[2] = true;
        if (separationMarkValid(dateToConvert))
            verificationTab[3] = true;

        functionOutput = true;
        for (int i = 0; i < 4; i++)
            functionOutput &= verificationTab[i];
        return functionOutput;
    }
    else
        return false;
}

bool TimeManager::yearValid(string &dateToConvert) {
    bool flag = true;
    for (int i = 0; i < 4; i++) {
        if (dateToConvert[i] >= zeroASCIICode && dateToConvert[i] <= nineASCIICode)
            flag &= true;
        else
            flag &= false;
    }
    return flag;
}

bool TimeManager::monthValid(string &dateToConvert) {
    bool flag = true;
    for (int i = 5; i < 6; i++) {
        if (dateToConvert[i] >= zeroASCIICode && dateToConvert[i] <= nineASCIICode)
            flag &= true;
        else
            flag &= false;
    }
    return flag;
}

bool TimeManager::dayValid(string &dateToConvert) {
    bool flag = true;
    for (int i = 9; i < 10; i++) {
        if (dateToConvert[i] >= zeroASCIICode && dateToConvert[i] <= nineASCIICode)
            flag &= true;
        else
            flag &= false;
    }
    return flag;
}

bool TimeManager::separationMarkValid(string &dateToConvert) {
    if (dateToConvert[4] == pauseASCIICode && dateToConvert[7] == pauseASCIICode)
        return true;
    else
        return false;
}

int TimeManager::countDaysOfMonth(int numberOfMonth, int year) // numberOfMonth to numer miesi¹ca od 1 do 12
{
    if (numberOfMonth < 8 && numberOfMonth % 2 != 0)
        return 31;
    else if (numberOfMonth < 8 && numberOfMonth % 2 == 0)
    {
        if (leapYear(year) && numberOfMonth == 2)
            return 29;
        else if (leapYear(year) == false && numberOfMonth == 2)
            return 28;
        else
            return 30;
    }
    else if (numberOfMonth > 7 && numberOfMonth % 2 == 0)
        return 31;
    else
        return 30;
}

bool TimeManager::leapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return true;
    else
        return false;
}

int TimeManager::startDateOfPreviousMonth() {
    string actualDate = getActualDateAsString();
    string startDateToConvert;
    string pause = "-";
    string zero = "0";
    int yearOfPreviousMonth;
    int previousMonth;

    if (month(actualDate) == 1) {
        yearOfPreviousMonth = year(actualDate) - 1;
        previousMonth = 12;
    } else {
        yearOfPreviousMonth = year(actualDate);
        previousMonth = month(actualDate) - 1;
    }

    if (previousMonth < 10)
        startDateToConvert = intToStr(yearOfPreviousMonth) + pause + zero + intToStr(previousMonth) + pause + zero + intToStr(1);
    else
        startDateToConvert = intToStr(yearOfPreviousMonth) + pause + intToStr(previousMonth) + pause + zero + intToStr(1);

    return getDateAsInteger(startDateToConvert);
}

int TimeManager::endDateOfPreviousMonth() {
    string actualDate = getActualDateAsString();
    string endDateToConvert;
    string pause = "-";
    string zero = "0";
    int yearOfPreviousMonth;
    int previousMonth;

    if (month(actualDate) == 1) {
        yearOfPreviousMonth = year(actualDate) - 1;
        previousMonth = 12;
    } else {
        yearOfPreviousMonth = year(actualDate);
        previousMonth = month(actualDate) - 1;
    }

    if (previousMonth < 10)
        endDateToConvert = intToStr(yearOfPreviousMonth) + pause + zero + intToStr(previousMonth) + pause + intToStr(countDaysOfMonth(previousMonth, yearOfPreviousMonth));
    else
        endDateToConvert = intToStr(yearOfPreviousMonth) + pause + intToStr(previousMonth) + zero + intToStr(countDaysOfMonth(previousMonth, yearOfPreviousMonth));

    return getDateAsInteger(endDateToConvert);
}

string TimeManager::intToStr(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
