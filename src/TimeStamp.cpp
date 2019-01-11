#include <cmath>
#include "TimeStamp.h"

//TimeStamp::TimeStamp(int day, int month, int year, int hour, int minute)
//    : Date(day, month, year) {
//    daysFromEpochStart += hour * DAYS_IN_HOUR;
//    daysFromEpochStart += minute * DAYS_IN_MINUTE;
//}
//
//bool TimeStamp::operator==(TimeStamp &anotherTimeStamp) {
//    return abs(daysFromEpochStart - anotherTimeStamp.daysFromEpochStart) < (DAYS_IN_MINUTE - 0.00001);
//}
//
//bool TimeStamp::operator<(TimeStamp &anotherTimeStamp) {
//    return (daysFromEpochStart - anotherTimeStamp.daysFromEpochStart) < 0;
//}
//
//bool TimeStamp::operator<=(TimeStamp &anotherTimeStamp) {
//    return operator<(anotherTimeStamp) || operator==(anotherTimeStamp);
//}
//
//bool TimeStamp::operator>(TimeStamp &anotherTimeStamp) {
//    return !operator<(anotherTimeStamp);
//}
//
//bool TimeStamp::operator>=(TimeStamp &anotherTimeStamp) {
//    return ! operator<=(anotherTimeStamp);
//}
//
//TimeStamp& TimeStamp::operator=(const TimeStamp &another) {
//    daysFromEpochStart = another.daysFromEpochStart;
//    return *this;
//}
//
//void TimeStamp::operator+(int hours) {
//    daysFromEpochStart += hours * DAYS_IN_HOUR;
//}
//
//void TimeStamp::operator-(int hours) {
//    daysFromEpochStart -= hours * DAYS_IN_HOUR;
//}
//
//

