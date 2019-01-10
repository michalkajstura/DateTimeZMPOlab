#include "TimeStamp.h"

TimeStamp::TimeStamp(int day, int month, int year, int hour, int minute)
    : Date(day, month, year) {
    daysFromEpochStart += hour * DAYS_IN_HOUR;
    daysFromEpochStart += minute * DAYS_IN_MINUTE;
}

bool TimeStamp::operator<(TimeStamp &anotherTimeStamp) {
}

bool TimeStamp::operator<=(TimeStamp &anotherTimeStamp) {
    return Date::operator<=(anotherTimeStamp);
}

bool TimeStamp::operator>(TimeStamp &anotherTimeStamp) {
    return Date::operator>(anotherTimeStamp);
}

bool TimeStamp::operator>=(TimeStamp &anotherTimeStamp) {
    return Date::operator>=(anotherTimeStamp);
}

bool TimeStamp::operator==(TimeStamp &anotherTimeStamp) {
    return Date::operator==(anotherTimeStamp);
}

