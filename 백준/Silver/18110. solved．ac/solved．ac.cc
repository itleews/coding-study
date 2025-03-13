#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }
    
    vector<int> levels(n);
    for (int i = 0; i < n; i++) {
        cin >> levels[i];
    }
    
    sort(levels.begin(), levels.end());
    
    int cut = round(n * 0.15);
    
    double sum = 0;
    for (int i = cut; i < n - cut; i++) {
        sum += levels[i];
    }
    double mean = sum / (n - 2 * cut);
    
    cout << round(mean) << '\n';
    return 0;
}