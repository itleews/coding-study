#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    char* str = new char[N];
    for (int i = 0; i < N; i++) {
        cin >> str[i];
        str[i] = str[i] - 'a' + 1;
    }
    
    long long hash = 0;
    long long r = 31;
    long long M = 1234567891;
    long long power_r = 1;
    
    for (int i = 0; i < N; i++) {
        hash = (hash + str[i] * power_r) % M;
        power_r = (power_r * r) % M;
    }
    
    cout << hash << endl;
    
    delete[] str;
}