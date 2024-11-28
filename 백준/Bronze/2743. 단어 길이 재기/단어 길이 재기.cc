#include <stdio.h>

int main() {
    char str[101];
    scanf("%s", str);
    for(int i = 0; i < 101; i++) {
        if(str[i] == '\0') {
            printf("%d", i);
            break;
        }
    }
}