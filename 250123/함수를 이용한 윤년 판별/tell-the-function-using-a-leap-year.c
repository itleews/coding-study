#include <stdio.h>

int isLeapYear(int year) {
    if ((year % 100 == 0) && (year % 400 != 0))
        return 0;
    else if (year % 4 == 0)
        return 1;
}

int main() {
    int year;
    scanf("%d", &year);
    if (isLeapYear(year))
        printf("true");
    else
        printf("false");
    return 0;
}