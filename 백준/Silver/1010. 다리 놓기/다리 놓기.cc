#include <iostream>
using namespace std;

int comb(int n, int m) {
    if (n == 0) return 1;
    int result = 1;
    for (int i = 0; i < n; ++i) {
        result *= (m - i);
        if (result % (i + 1) == 0) {
            result /= (i + 1);
        } 
        else {
            result = result / (i + 1);
        }
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        cout << comb(n, m) << endl; 
    }
    return 0;
}