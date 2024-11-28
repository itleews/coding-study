#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int max = a[0], min = a[0];
    for(int j = 0; j < n; j++) {
        if(max < a[j])
            max = a[j];
    }
    for(int k = 0; k < n; k++) {
        if(min > a[k])
            min = a[k];
    }
    printf("%d %d", min, max);
}