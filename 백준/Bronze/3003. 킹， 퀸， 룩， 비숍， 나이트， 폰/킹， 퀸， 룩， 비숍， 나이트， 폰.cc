#include <stdio.h>

int main() {
    int out[6] = {1, 1, 2, 2, 2, 8};
    int in[6];
    scanf("%d %d %d %d %d %d", &in[0], &in[1], &in[2], &in[3], &in[4], &in[5]);
    
    for(int i = 0; i < 6; i++) {
        out[i] = out[i] - in[i];
        printf("%d ", out[i]);
    }

    return 0;
}