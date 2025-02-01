#include <stdio.h>

void func(int num) {
    if ((num % 2 == 0) && ((num / 10 + num % 10) % 5 == 0)) {
        printf("Yes");

    }
    else {
        printf("No");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    func(n);
    return 0;
}