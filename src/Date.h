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
const int NUM_OF_MONTHS = 12;
const int DAYS_IN_MONTH[NUM_OF_MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int MINUTES_IN_HOUR = 60;
const int HOURS_IN_DAY = 24;
const int MINUTES_IN_DAY = MINUTES_IN_HOUR * HOURS_IN_DAY;

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
    virtual int daysBetween(double timePointInMinutes);
    int getDay();
    int getMonth();
    int getYear();
    string toString();
private:
    bool isLeapYear(int year);
    int validateDay(int day, int month, tm* now);
    int validateMonth(int month, tm* now);

protected:
    // unsigned long would be much better choice but I have to use double
    double minutesFromEpochStart;

};

//ostream & operator << (ostream &out, const Date &date)
//{
//    out << ;
//    out << "+i" << c.imag << endl;
//    return out;
//}


#endif //DATETIME_DATE_H
