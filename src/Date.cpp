#include "Date.h"

Date::Date(int day, int month, int year) {
    time_t timeNow = time(0);
    tm* now = localtime(&timeNow);
    month = validateMonth(month, now);
    day = validateDay(day, month, now);

    minutesFromEpochStart = (day - 1) * MINUTES_IN_DAY;

    for (int m=0; m < month - 1; m++) {
        if (m == 1 && isLeapYear(year))
            minutesFromEpochStart += (DAYS_IN_MONTH[m] + 1) * MINUTES_IN_DAY;
        else
            minutesFromEpochStart += DAYS_IN_MONTH[m] * MINUTES_IN_DAY;
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

int Date::daysBetween(Date &anotherDate) {
    return daysBetween(anotherDate.minutesFromEpochStart);
}

int Date::daysBetween(double timePointInMinutes) {
    int difference = minutesFromEpochStart - timePointInMinutes;
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

bool Date::operator==(Date &anotherDate) {
    return daysBetween(anotherDate) == 0;
}

bool Date::operator>(Date &anotherDate) {
    return daysBetween(anotherDate) > 0;
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

int Date::validateDay(int day, int month, tm* now) {
    return (day > 0 && day <= DAYS_IN_MONTH[month]) ? day : now->tm_mday;
}

int Date::validateMonth(int month, tm* now) {
    // Get time now
    return (month > 0 && month <= NUM_OF_MONTHS) ? month : now->tm_mon;
}

int Date::getYear() {
    double minutes = 0;
    double absMinutesFromStart = abs(minutesFromEpochStart);
    int year = 0;
    while (minutes < absMinutesFromStart) {
        int daysInYear =  (isLeapYear(START_EPOCH_YEAR + year)) ? DAYS_IN_YEAR + 1 : DAYS_IN_YEAR;
        minutes += daysInYear * MINUTES_IN_DAY;
        if (minutes <= absMinutesFromStart)
            year += 1;
    }
    year = (minutesFromEpochStart < 0) ? -year : year;
    return year;
}
