#include <iostream>
using namespace std;

bool isPrime (int N) {
    if (N < 2) return false;
    for (int i = 2; i * i <= N; i++) {
        if (N % i == 0) return false;
    }
    return true;
}

int main() {
    int N;
    int prime = 0;
    cin >> N;
    
    int* num = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    
    for (int i = 0; i < N; i++) {
        if (isPrime(num[i])) {
            prime++;
        }
    }
    
    cout << prime << endl;
    
    delete[] num;
    
    return 0;
}