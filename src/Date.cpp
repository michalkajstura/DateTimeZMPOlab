#include <cfloat>
#include <iostream>
#include <climits>
#include <cmath>
#include "Date.h"

Date::Date(int day, int month, int year) {
    // TODO validation
    daysFromEpochStart = day;

    for (int m=0; m < month - 1; m++) {
        daysFromEpochStart += DAYS_IN_MONTH[m];
    }

    int change = (year > START_EPOCH_YEAR) ? 1 : -1;
    for (int y = START_EPOCH_YEAR; y != year; y += change) {
        int daysInYear = (isLeapYear(year)) ? DAYS_IN_YEAR + 1: DAYS_IN_YEAR;
        daysFromEpochStart += daysInYear;
    }
}

Date::Date(Date &anotherDate) {
    daysFromEpochStart = anotherDate.daysFromEpochStart;
}

bool Date::isLeapYear(int year) {
    int hundreds = LEAP_YEAR_RANGE * 100;
    return (year % hundreds == 0)
            || (year % 100 != 0 && year % LEAP_YEAR_RANGE == 0);
}

int Date::daysBetween(Date &anotherDate) {
    double difference = (daysFromEpochStart - anotherDate.daysFromEpochStart);
    return abs(difference);
}

double Date::daysBetweenDouble(Date &anotherDate) {
    return daysFromEpochStart - anotherDate.daysFromEpochStart;
}

Date Date::operator+(int daysFromNow) {
    daysFromEpochStart += daysFromNow;
}

Date Date::operator-(int daysFromNow) {
    daysFromEpochStart -= daysFromNow;
}

bool Date::operator==(Date &anotherDate) {
    return fabs(daysBetweenDouble(anotherDate)) < ONE_SECOND_IN_DAYS;
}

bool Date::operator>(Date &anotherDate) {
    return daysBetweenDouble(anotherDate) > 0;
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

