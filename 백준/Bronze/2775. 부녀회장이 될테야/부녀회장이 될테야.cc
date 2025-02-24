#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    int apt[15][15] = {0};
    
    for (int i = 1; i <= 14; i++) {
        apt[0][i] = i;
    }
    
    for (int j = 1; j <= 14; j++) {
        for (int k = 1; k <= 14; k++) {
            apt[j][k] = apt[j - 1][k] + apt[j][k - 1];
        }
    }
    
    for (int i = 0; i < T; i++) {
        int k, n;
        cin >> k;
        cin >> n;
        cout << apt[k][n] << endl;
    }
    
    return 0;
}