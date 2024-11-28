#include <stdio.h>

int main() {
    int a[9];
    for(int i = 0; i < 9; i++)
        scanf("%d", &a[i]);
    int max = a[0], max_n = 0;
    for(int j = 0; j < 9; j++) {
        if(max < a[j]) {
            max = a[j];
            max_n = j;
        }
    }
    printf("%d\n%d", max, max_n + 1);
}