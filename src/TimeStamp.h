#ifndef DATETIME_TIMESTAMP_H
#define DATETIME_TIMESTAMP_H

#include "Date.h"

const double DAYS_IN_MINUTE = 1. / (60 * 24);
const double DAYS_IN_HOUR = 1. / 24.;

class TimeStamp : public Date {

public:
    TimeStamp(int day, int month, int year, int hour, int minute);

    void operator+(int hours) override;
    void operator-(int hours) override;
    TimeStamp &operator=(const TimeStamp &another);
    bool operator<(TimeStamp &anotherTimeStamp);
    bool operator<=(TimeStamp &anotherTimeStamp);
    bool operator>(TimeStamp &anotherTimeStamp);
    bool operator>=(TimeStamp &anotherTimeStamp);
    bool operator==(TimeStamp &anotherTimeStamp);
private:
};


#endif //DATETIME_TIMESTAMP_H
