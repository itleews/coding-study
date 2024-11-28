#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n];
    for(int x = 0; x < n; x++)
        a[x] = x + 1;
    for(int y = 0; y < m; y++) {
        int i, j, k;
        scanf("%d %d", &i, &j);
        k = a[i - 1];
        a[i - 1] = a[j - 1];
        a[j - 1] = k;
    }
    for(int z = 0; z < n; z++)
        printf("%d ", a[z]);
}