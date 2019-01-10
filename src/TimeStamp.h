#ifndef DATETIME_TIMESTAMP_H
#define DATETIME_TIMESTAMP_H

#include "Date.h"

class TimeStamp : public Date {

public:
    TimeStamp(int day, int month, int year, int hour, int minute);

    bool operator<(TimeStamp &anotherTimeStamp);
    bool operator<=(TimeStamp &anotherTimeStamp);
    bool operator>(TimeStamp &anotherTimeStamp);
    bool operator>=(TimeStamp &anotherTimeStamp);
    bool operator==(TimeStamp &anotherTimeStamp);
    int daysBetween(TimeStamp &anotherTimeStamp);

private:
    bool hoursAndMinutesGreater(TimeStamp &another);
};


#endif //DATETIME_TIMESTAMP_H
