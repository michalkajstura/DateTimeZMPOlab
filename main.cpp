#include <iostream>
#include "src/Date.h"
#include "src/TimeStamp.h"

int main() {
    Date d(31, 12, 123333);
    Date d2(2, 6, 1231);
//    Date d2(13, 1, 5019);
//    cout << (d == d2) << endl;
//    cout << (d > d2) << endl;
//    cout << (d <= d2) << endl;
    cout << d.getYear() << endl;
    cout << d2.getYear() << endl;

//    cout << d.daysBetween(d2) << endl;
    return 0;
}