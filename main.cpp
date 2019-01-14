#include <iostream>
#include "src/Date.h"
#include "src/TimeStamp.h"

int main() {
    Date d(22, 1, 2019); /////!!!!!!!
    Date d2(12, 1, 2019);
    cout << (d2 - d) << endl;
//    Date d2(13, 1, 5019);
//    cout << d.getDay() << endl;
//    cout << d.getMonth() << endl;
//    cout << d.getYear() << endl;
//
//
//    TimeStamp ts(2, 4, 2019, 10, 1);
//    cout << ts.getHour() << endl;
//    cout << ts.getMinute() << endl;

    TimeStamp ts2(2, 4, 2019, 21, 30);
    TimeStamp ts3(2, 4, 2019, 20, 31);
    cout << ts2 << endl;
    cout << ts3 << endl;


//    cout << d.daysBetween(d2) << endl;
    return 0;
}