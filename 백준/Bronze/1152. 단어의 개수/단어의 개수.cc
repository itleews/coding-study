#include <stdio.h>

int main() {
    char str[1000001];
    scanf("%[^\n]s", str);
    int cnt = 0;
    if(str[0] != ' ') cnt++;
    int i = 0;
    while (str[i]) {
        if(str[i] == ' ') cnt++;
        i++;
    }
    if(str[i - 1] == ' ') cnt--;

    printf("%d\n", cnt);
}