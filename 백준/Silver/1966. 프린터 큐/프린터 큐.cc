#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        
        queue<pair<int, int>> q; // (중요도, 인덱스)
        priority_queue<int> pq; // 중요도를 저장하는 우선순위 큐
        
        for (int i = 0; i < N; i++) {
            int priority;
            cin >> priority;
            q.push({priority, i});
            pq.push(priority);
        }
        
        int count = 0;
        
        while (!q.empty()) {
            int cur_priority = q.front().first;
            int cur_index = q.front().second;
            q.pop();
            
            if (cur_priority == pq.top()) {
                count++;
                pq.pop();
                
                if (cur_index == M) {
                    cout << count << "\n";
                    break;
                }
            }
            else {
                q.push({cur_priority, cur_index});
            }
        }
    }
    return 0;
}