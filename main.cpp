#include <iostream>
#include "src/Date.h"

int main() {
    Date d(6, 4, 2019);
    Date d2(10, 1, 2019);
    cout << d.daysBetween(d2) << endl;
    return 0;
}