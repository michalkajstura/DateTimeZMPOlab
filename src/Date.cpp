#include "Date.h"

Date::Date(int day, int month, int year) {
    time_t timeNow = time(0);
    tm* now = localtime(&timeNow);
    month = validateMonth(month, now);
    day = validateDay(day, month, year, now);

    minutesFromEpochStart = (day - 1) * MINUTES_IN_DAY;

    for (int m=0; m < month - 1; m++) {
        minutesFromEpochStart += DAYS_IN_MONTH[isLeapYear(year)][m] * MINUTES_IN_DAY;
    }

    int change = (year > START_EPOCH_YEAR) ? 1 : -1;
    for (int y = START_EPOCH_YEAR; y != year; y += change) {
        int daysInYear = (isLeapYear(y)) ? DAYS_IN_YEAR + 1: DAYS_IN_YEAR;
        minutesFromEpochStart += daysInYear * MINUTES_IN_DAY * change;
    }
}

Date::Date(Date &anotherDate) {
    minutesFromEpochStart = anotherDate.minutesFromEpochStart;
}

bool Date::isLeapYear(int year) {
    int hundreds = LEAP_YEAR_RANGE * 100;
    return (year % hundreds == 0)
            || (year % 100 != 0 && year % LEAP_YEAR_RANGE == 0);
}

long Date::daysBetween(Date &anotherDate) {
    long difference = minutesFromEpochStart - anotherDate.minutesFromEpochStart;
    return difference / MINUTES_IN_DAY;
}

Date& Date::operator=(const Date &anotherDate) {
    minutesFromEpochStart = anotherDate.minutesFromEpochStart;
    return *this;
}

void Date::operator+(int daysFromNow) {
    minutesFromEpochStart += daysFromNow * MINUTES_IN_DAY;
}

void Date::operator-(int daysFromNow) {
    minutesFromEpochStart -= daysFromNow * MINUTES_IN_DAY;
}

int Date::operator-(Date &anotherDate) {
    return daysBetween(anotherDate);
}

bool Date::operator==(Date &anotherDate) {
    return daysBetween(anotherDate) == 0;
}

bool Date::operator>(Date &anotherDate) {
    return daysBetween(anotherDate)> 0;
}

bool Date::operator<(Date &anotherDate) {
    return ! this->operator>(anotherDate);
}

bool Date::operator>=(Date &anotherDate) {
    return this->operator==(anotherDate) || this->operator>(anotherDate);
}

bool Date::operator<=(Date &anotherDate) {
    return ! this->operator>=(anotherDate);
}

int Date::validateDay(int day, int month, int year, tm* now) {
    return (day > 0 && day <= DAYS_IN_MONTH[isLeapYear(year)][month]) ? day : now->tm_mday;
}

int Date::validateMonth(int month, tm* now) {
    // Get time now
    return (month > 0 && month <= NUM_OF_MONTHS) ? month : now->tm_mon;
}

int Date::getYear() {
    double minutes = 0;
    return calculateYear(minutes);
}

int Date::getMonth(){
    double minutes = 0;
    int year = calculateYear(minutes);
    return calculateMonths(year, minutes);
}

int Date::getDay() {
    double minutes = 0;
    int year = calculateYear(minutes);
    calculateMonths(year, minutes);
    return calculateDay(minutes);
}

int Date::calculateDay(double &minutes) const {
    int day= (abs(minutesFromEpochStart)- minutes) / MINUTES_IN_DAY + 1;
    minutes += MINUTES_IN_DAY;
    return day;
}

int Date::calculateMonths(int year, double &minutes) const {
    int month = 1;
    bool nextIteration = true;
    while (month <= NUM_OF_MONTHS
           && nextIteration) {
        minutes += DAYS_IN_MONTH[isLeapYear(year)][month-1] * MINUTES_IN_DAY;
        if (minutes <= abs(minutesFromEpochStart)) {
            month++;
        } else
            nextIteration = false;
    }
    minutes -= DAYS_IN_MONTH[isLeapYear(year)][month - 1] * MINUTES_IN_DAY;
    return month;
}

int Date::calculateYear(double &minutes) {
    int year= START_EPOCH_YEAR;
    bool nextIteration = true;
    while (nextIteration) {
        minutes += numberOfDaysInYear(year) * MINUTES_IN_DAY;
        if (minutes < abs(minutesFromEpochStart))
            year += 1;
        else
            nextIteration = false;
    }
    minutes -= numberOfDaysInYear(year) * MINUTES_IN_DAY;
    year= (minutesFromEpochStart < 0) ? -year : year;
    return year;
}

int Date::numberOfDaysInYear(int year) {
    if (isLeapYear(year))
        return DAYS_IN_YEAR + 1;
    else
        return DAYS_IN_YEAR;
}

ostream & operator << (ostream &out, Date& date){
    out << to_string(date.getDay()) + "/";
    out << to_string(date.getMonth()) + "/";
    out << to_string(date.getYear());
    return out;
}