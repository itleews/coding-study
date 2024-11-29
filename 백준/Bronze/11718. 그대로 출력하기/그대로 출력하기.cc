#include <stdio.h>

int main() {
    char string;
    
    while(scanf("%c", &string) == 1) {   
        printf("%c", string);
    }
    
    return 0;
}