#include <stdio.h>

int main() {
    int a[31] = {0, };
    int x;
    for(int i = 0; i < 28; i++) {
        scanf("%d", &x);
        a[x] = 1;
    }
    for(int j = 1; j <= 30; j++) {
        if(a[j] != 1)
            printf("%d\n", j);
    }
}