#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N;
    vector<int> Card(N);
    for (int i = 0; i < N; i++) {
        cin >> Card[i];
    }
    
    sort(Card.begin(), Card.end());
    
    cin >> M;
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        
        int count = upper_bound(Card.begin(), Card.end(), x) - lower_bound(Card.begin(), Card.end(), x);
        cout << count << " ";
    }
    cout << '\n';
    return 0;
}