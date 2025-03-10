#include <iostream>
using namespace std;

bool isPrime (int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int M, N;
    cin >> M >> N;
    
    while (M <= N) {
        if (isPrime(M)) {
            cout << M << '\n';
        }
        M++;
    }
    
    return 0;
}