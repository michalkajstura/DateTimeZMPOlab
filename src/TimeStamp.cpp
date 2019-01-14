#include <cmath>
#include "TimeStamp.h"

TimeStamp::TimeStamp(int day, int month, int year, int hour, int minute)
    : Date(day, month, year) {
    minutesFromEpochStart += hour * MINUTES_IN_HOUR;
    minutesFromEpochStart += minute;
}

bool TimeStamp::operator==(TimeStamp &anotherTimeStamp) {
    return abs(minutesFromEpochStart - anotherTimeStamp.minutesFromEpochStart) < DBL_EPSILON;
}

bool TimeStamp::operator<(TimeStamp &anotherTimeStamp) {
    return (minutesFromEpochStart - anotherTimeStamp.minutesFromEpochStart) < 0;
}

bool TimeStamp::operator<=(TimeStamp &anotherTimeStamp) {
    return operator<(anotherTimeStamp) || operator==(anotherTimeStamp);
}

bool TimeStamp::operator>(TimeStamp &anotherTimeStamp) {
    return !operator<(anotherTimeStamp);
}

bool TimeStamp::operator>=(TimeStamp &anotherTimeStamp) {
    return ! operator<=(anotherTimeStamp);
}

TimeStamp& TimeStamp::operator=(const TimeStamp &another) {
    minutesFromEpochStart = another.minutesFromEpochStart;
    return *this;
}

void TimeStamp::operator+(int hours) {
    minutesFromEpochStart += hours * DAYS_IN_HOUR;
}

void TimeStamp::operator-(int hours) {
    minutesFromEpochStart -= hours * DAYS_IN_HOUR;
}

int TimeStamp::getHour() {
    double minutes = 0;
    int year = calculateYear(minutes);
    calculateMonths(year, minutes);
    calculateDay(minutes);
    int hour = (abs(minutesFromEpochStart) - minutes) / MINUTES_IN_HOUR;
    return hour;
}

int TimeStamp::getMinute() {
    double minutes = 0;
    int year = calculateYear(minutes);
    calculateMonths(year, minutes);
    calculateDay(minutes);
    int hour = (abs(minutesFromEpochStart) - minutes) / MINUTES_IN_HOUR;
    minutes -= hour * MINUTES_IN_HOUR;
    return  abs(minutesFromEpochStart) - minutes;
}

ostream & operator << (ostream &out, TimeStamp& timeStamp){
    out << to_string(timeStamp.getHour()) + ":";
    out << to_string(timeStamp.getMinute()) + " ";
    out << to_string(timeStamp.getDay()) + "/";
    out << to_string(timeStamp.getMonth()) + "/";
    out << to_string(timeStamp.getYear());
    return out;
}
