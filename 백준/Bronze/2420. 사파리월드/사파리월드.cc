#include <iostream>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    long long sub = N - M;
    
    if (sub < 0) {
        cout << -sub << endl;
    } else {
        cout << sub << endl;
    }
    
    return 0;
}