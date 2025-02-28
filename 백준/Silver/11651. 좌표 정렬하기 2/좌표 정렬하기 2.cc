#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<pair<int, int>> points(N);
    
    for (int i = 0; i < N; i++) {
        cin >> points[i].first >> points[i].second;
    }
    
    sort (points.begin(), points.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });
    
    for (auto p : points) {
        cout << p.first << " " << p.second << "\n";
    }
    
    return 0;
}