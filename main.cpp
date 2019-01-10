#include <iostream>
#include "src/Date.h"

int main() {
    Date d(13, 06, 123);
    Date d2(10, 1, 2019);
    Date d3(10, 1, 2019);
    cout << (d < d2) << endl;
    cout << (d3 == d2) << endl;
    cout << (d3 >= d2) << endl;
//    cout << d.daysBetween(d2) << endl;
    return 0;
}