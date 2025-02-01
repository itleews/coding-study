#include <stdio.h>

int isPrime(int n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int sumPrime(int x, int y) {
    int sum = 0;
    for (; x <= y; x++) {
        if(isPrime(x) == 1)
            sum += x;
    }
    return sum;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", sumPrime(a, b));
    return 0;
}