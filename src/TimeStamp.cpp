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
    return get<3>(calculateDDMMYYYYHHmm());
}

int TimeStamp::getMinute() {
    return get<4>(calculateDDMMYYYYHHmm());
}


