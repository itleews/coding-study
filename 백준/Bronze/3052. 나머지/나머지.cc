#include <stdio.h>

int main() {
    int arr[10], count, result = 0;
    for(int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
        arr[i] = arr[i] % 42;
    }
    for(int j = 0; j < 10; j++) {
        count = 0;
        for(int k = 0; k < j; k++) {
            if(arr[j] == arr[k])
                count++;
        }
        if(count == 0)
            result++;
    }
    printf("%d", result);
}