#include <iostream>
#include "src/Date.h"
#include "src/TimeStamp.h"

int main() {
    Date d(2, 1, 2019); /////!!!!!!!
    Date d2(2, 6, 1231);
//    Date d2(13, 1, 5019);
//    cout << d.getDay() << endl;
//    cout << d.getMonth() << endl;
//    cout << d.getYear() << endl;
cout << d << endl;
//

    TimeStamp ts(2, 4, 2019, 10, 1);
    cout << ts.getHour() << endl;
    cout << ts.getMinute() << endl;

    TimeStamp ts2(2, 4, 2019, 21, 30);
    TimeStamp ts3(2, 4, 2019, 20, 31);

//    cout << d.daysBetween(d2) << endl;
    return 0;
}