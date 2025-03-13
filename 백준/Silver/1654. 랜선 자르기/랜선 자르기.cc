#include <iostream>
using namespace std;

int K, N;
long long lan[10000], low = 1, high, answer;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> K >> N;
    for (int i = 0; i < K; i++) {
        cin >> lan[i];
        high = max(high, lan[i]);
    }
    
    while (low <= high) {
        long long mid = (low + high) / 2, count = 0;
        for (int i = 0; i < K; i++) {
            count += lan[i] / mid;
        }
        
        if (count >= N) answer = mid, low = mid + 1;
        else high = mid - 1;
    }
    
    cout << answer << '\n';
    return 0;
}