#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int zero = 0;
    for (int i = 5; i <= N; i *= 5) {
        zero += N / i;
    }
    
    cout << zero << '\n';
    return 0;
}