// @todo: Add a file documentation header as explained in the specs ...

// You should document [not necessary for grading but an excellent habit
// to acquire] your implementation of function decimal_to_roman to aid
// in debugging and maintenance not only by yourself but by others in
// your software development team ...

// Remember, the function-level documentation header in q.h is primarily
// meant for your clients. The documentation header here is primarily for
// use by you [and other on your team] solely to aid maintenance and
// debugging tasks ...

// @todo: Add necessary C standard library headers here ...
#include "q.h"
// @todo: Provide the definition of function decimal_to_roman that
// matches the declaration in q.h ...

void decimal_to_roman(int num) {
    int decimalVal[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    for (int i = 0; num > 0; i++) {
        while (num >= decimalVal[i]) {
            printf("%s", roman[i]);
            num -= decimalVal[i];
            
        }
        printf("\n");
    }
}