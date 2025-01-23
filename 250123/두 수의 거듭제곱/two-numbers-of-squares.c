#include <stdio.h>

int power(int x, int y) {
    int p = 1;
    for(int i = 0; i < y; i++)
        p *= x;
    return p;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", power(a, b));
    return 0;
}