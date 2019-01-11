#include <iostream>
#include "src/Date.h"
#include "src/TimeStamp.h"

int main() {
    Date d(3, 3, 2019);
    TimeStamp ts(3, 3, 2019, 12, 00);
    TimeStamp ts2(3, 3, 2019, 12, 30);
    d+3;

//    cout << d.daysBetween(d2) << endl;
    return 0;
}