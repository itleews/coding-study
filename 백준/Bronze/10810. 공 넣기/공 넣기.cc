#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int baskets[N];
    for (int i = 0; i < N; i++) {
        baskets[i] = 0;  // 초기값은 모두 0으로 설정
    }

    for (int m = 0; m < M; m++) {
        int i, j, k;
        scanf("%d %d %d", &i, &j, &k);
        for (int b = i - 1; b < j; b++) {
            baskets[b] = k;  // i, j는 1부터 시작하므로 인덱스를 맞추기 위해 -1 해줌
        }
    }

    for (int i = 0; i < N; i++) {
        printf("%d ", baskets[i]);
    }

    return 0;
}
