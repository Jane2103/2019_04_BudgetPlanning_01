#include "TimeManager.h"

string TimeManager::getActualDateAsString() {
    time(&rawTime);
    timeInfo = localtime(&rawTime);

    strftime(yyyy_mm_dd_Date, DATE_FORMAT_SIZE, "%Y-%m-%d", timeInfo);
    string actualDateAsString = yyyy_mm_dd_Date;

    return actualDateAsString;
}

int TimeManager::year(string dateAsString) {
    string yearToConvert = "";
    for (int i = 0; i < 4; i++)
        yearToConvert += yyyy_mm_dd_Date[i];
    return atoi(yearToConvert.c_str());
}

int TimeManager::month(string dateAsString) {
    string monthToConvert = "";
    for (int i = 5; i < 7; i++)
        monthToConvert += yyyy_mm_dd_Date[i];
    return atoi(monthToConvert.c_str());
}

int TimeManager::day(string dateAsString) {
    string dayToConvert = "";
    for (int i = 9; i < DATE_FORMAT_SIZE; i++)
        dayToConvert += yyyy_mm_dd_Date[i];
    return atoi(dayToConvert.c_str());
}

bool TimeManager::dayCorrect(string dateAsString) {
    int minYear = 2000;
    int minMonth = 1;
    int minDay = 1;

    int providedYear, providedMonth, providedDay;
    int maxYear, maxMonth, maxDay;

    providedYear = year(dateAsString);
    providedMonth = month(dateAsString);
    providedDay = day(dateAsString);

    maxYear = year(getActualDateAsString());
    maxMonth = month(getActualDateAsString());
    maxDay = day(getActualDateAsString());

    if (providedYear >= minYear && providedYear <= maxYear
        && providedMonth >= minMonth && providedMonth <= maxMonth
        && providedDay >= minDay && providedDay <= maxDay)
        return true;
    else
        return false;
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
