#ifndef DATETIME_DATE_H
#define DATETIME_DATE_H

const int DEFAULT_DAY = 0;
const int DEFAULT_MONTH = 0;
const int DEFAULT_YEAR = 0;

class Date {
public:
    Date();
    Date(int day);
    Date(int day, int month);
    Date(int day, int month, int year);
    Date(Date &anotherDate);
    ~Date();

    Date operator+(int daysFromNow);
    Date operator-(int daysFromNow);
    bool operator<(Date &anotherDate);
    bool operator<=(Date &anotherDate);
    bool operator>(Date &anotherDate);
    bool operator>=(Date &anotherDate);
    bool operator==(Date &anotherDate);

    int daysBetween(Date &anotherDate);

private:
    double secondsFromEpochStart;
};


#endif //DATETIME_DATE_H
