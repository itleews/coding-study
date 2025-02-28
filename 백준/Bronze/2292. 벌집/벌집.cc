#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    if (N == 1) {
        cout << 1;
        return 0;
    }
    
    int layer = 1;
    int maxNum = 1;
    
    while (maxNum < N) {
        maxNum += 6 * layer;
        layer++;
    }
    
    cout << layer;
    return 0;
}