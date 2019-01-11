#ifndef DATETIME_DATE_H
#define DATETIME_DATE_H

#include <cfloat>
#include <iostream>
#include <climits>
#include <cmath>

const int DEFAULT_DAY = 0;
const int DEFAULT_MONTH = 0;
const int DEFAULT_YEAR = 0;
const int DAYS_IN_YEAR = 365;
const int START_EPOCH_YEAR = 0;
const int LEAP_YEAR_RANGE = 4;
const int NUM_OF_DAYS_IN_MONTH = 12;
const int DAYS_IN_MONTH[NUM_OF_DAYS_IN_MONTH] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

using namespace std;

class Date {
public:
    Date(int day=DEFAULT_DAY, int month=DEFAULT_MONTH, int year=DEFAULT_YEAR);
    Date(Date &anotherDate);

//    Date& operator=(Date &anotherDate);
    virtual void operator+(int daysFromNow);
    virtual void operator-(int daysFromNow);
    Date& operator=(const Date &anotherDate);

    virtual bool operator<(Date &anotherDate);
    virtual bool operator<=(Date &anotherDate);
    virtual bool operator>(Date &anotherDate);
    virtual bool operator>=(Date &anotherDate);
    virtual bool operator==(Date &anotherDate);
    virtual int daysBetween(Date &anotherDate);

private:
    bool isLeapYear(int year);
    int validateDay(int day, int month, tm* now);
    int validateMonth(int month, tm* now);

protected:
    // unsigned long would be much better choice but I have to use double
    double daysFromEpochStart;

};


#endif //DATETIME_DATE_H
