#include <stdio.h>

int func(int num) {
    int sum = 0;
    for(int i = 1; i <= num; i++) {
        sum += i;
    }
    return (sum / 10);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", func(n));
    return 0;
}