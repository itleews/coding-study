#include <stdio.h>

int main() {
    char str[101];
    char atoz[26];
    for(int i = 0; i < 26; i++)
        atoz[i] = -1;
    scanf("%s", str);
    for(int i = 97; i <= 122; i++) {
        for(int j = 0; str[j] != '\0'; j++) {
            if(i == str[j]) {
                atoz[i - 97] = j;
                break;
            }
        }
    }
    for(int i = 0; i < 26; i++)
        printf("%d ", atoz[i]);
}