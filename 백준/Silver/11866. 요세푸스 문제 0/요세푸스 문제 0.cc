#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    
    deque<int> dq;
    
    for (int i = 1; i <= N; i++) {
        dq.push_back(i);
    }
    
    vector<int> result;
    
    while (!dq.empty()) {
        for (int i = 0; i < K - 1; i++) {
            dq.push_back(dq.front());
            dq.pop_front();
        }
        result.push_back(dq.front());
        dq.pop_front();
    }
    
    cout << "<";
    for (int i = 0; i < result.size(); i++) {
        if (i != 0) cout << ", ";
        cout << result[i];
    }
    cout << ">" << '\n';
    return 0;
}