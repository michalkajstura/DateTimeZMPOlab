#ifndef DATETIME_DATE_H
#define DATETIME_DATE_H

#include <cfloat>
#include <iostream>
#include <climits>
#include <cmath>
#include <tuple>

const int DEFAULT_DAY = 0;
const int DEFAULT_MONTH = 0;
const int DEFAULT_YEAR = 0;
const int DAYS_IN_YEAR = 365;
const int START_EPOCH_YEAR = 0;
const int LEAP_YEAR_RANGE = 4;
const int NUM_OF_MONTHS = 12;
const int MINUTES_IN_HOUR = 60;
const int HOURS_IN_DAY = 24;
const int MINUTES_IN_DAY = MINUTES_IN_HOUR * HOURS_IN_DAY;
const int DAYS_IN_MONTH[2][NUM_OF_MONTHS] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                                             {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

using namespace std;

class Date {
public:
    Date(int day=DEFAULT_DAY, int month=DEFAULT_MONTH, int year=DEFAULT_YEAR);
    Date(Date &anotherDate);

//    Date& operator=(Date &anotherDate);
    virtual void operator+(int daysFromNow);
    virtual void operator-(int daysFromNow);
    virtual int operator-(Date &anotherDate);
    Date& operator=(const Date &anotherDate);
    virtual bool operator<(Date &anotherDate);
    virtual bool operator<=(Date &anotherDate);
    virtual bool operator>(Date &anotherDate);
    virtual bool operator>=(Date &anotherDate);
    virtual bool operator==(Date &anotherDate);
    friend ostream & operator << (ostream &out, Date&date);

    int getDay();
    int getMonth();
    int getYear();
    string toString();
private:
    static bool isLeapYear(int year);
    int validateDay(int day, int month, int year, tm* now);
    int validateMonth(int month, tm* now);
    int numberOfDaysInYear(int year) ;
    virtual long daysBetween(Date &anotherDate);



protected:
    // unsigned long would be much better choice but I have to use double
    double minutesFromEpochStart;

    int calculateYear(double &minutes);
    int calculateMonths(int year, double &minutes) const;
    int calculateDay(double &minutes) const;
};



#endif //DATETIME_DATE_H
