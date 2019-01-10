#ifndef DATETIME_DATE_H
#define DATETIME_DATE_H

#include <chrono>

const int DEFAULT_DAY = 0;
const int DEFAULT_MONTH = 0;
const int DEFAULT_YEAR = 0;
const int SECONDS_IN_DAY = 60 * 60 * 24;
const int DAYS_IN_YEAR = 365;
const int START_EPOCH_YEAR = 0;
const int LEAP_YEAR_RANGE = 4;
const int DAYS_IN_MONTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

using namespace std;

class Date {
public:
    Date(int day=DEFAULT_DAY, int month=DEFAULT_MONTH, int year=DEFAULT_YEAR);
    Date(Date &anotherDate);

//    Date operator+(int daysFromNow);
//    Date operator-(int daysFromNow);
//    bool operator<(Date &anotherDate);
//    bool operator<=(Date &anotherDate);
//    bool operator>(Date &anotherDate);
//    bool operator>=(Date &anotherDate);
//    bool operator==(Date &anotherDate);

    int daysBetween(Date &anotherDate);

private:
    bool isLeapYear(int year);
    double daysFromEpochStart;

};


#endif //DATETIME_DATE_H
