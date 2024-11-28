#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    char start[t], end[t];
    for(int i = 0; i < t; i++) {
        char str[1001];
        scanf("%s", str);
        int cnt = 0;
        while(str[cnt] != '\0') {
            cnt++;
        }
        start[i] = str[0];
        end[i] = str[cnt - 1];
    }
    for(int i = 0; i < t; i++) {
        printf("%c%c\n", start[i], end[i]);

    }
}