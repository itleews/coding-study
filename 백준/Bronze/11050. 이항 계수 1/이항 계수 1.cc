#include <iostream>
using namespace std;

int factorial(int num) {
    int result = 1;
    for (int i = 1; i <= num; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int N, K;
    cin >> N >> K;
    
    cout << (factorial(N) / (factorial(N - K) * factorial(K))) << endl;
    return 0;
}