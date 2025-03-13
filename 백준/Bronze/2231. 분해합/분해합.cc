#include <iostream>
using namespace std;

int decompositionSum(int M) {
    int sum = M;
    while (M > 0) {
        sum += M % 10;
        M /= 10;
    }
    return sum;
}

int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        if (decompositionSum(i) == N) {
            cout << i;
            return 0;
        }
    }
    
    cout << 0;
    return 0;
}