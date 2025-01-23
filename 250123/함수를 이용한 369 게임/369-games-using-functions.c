#include <stdio.h>

int contains369(int num) {
    while (num > 0) {
        int digit = num % 10;
        if (digit == 3 || digit == 6 || digit == 9) {
            return 1;
        }
        num /= 10;
    }
    return 0;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    int count = 0;
    for (; a <= b; a++) {
        if (a % 3 == 0)
            count++;
        else if (contains369(a) == 1)
            count++;
    }

    printf("%d\n", count);
    return 0;
}
