#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    vector<string> not_heard(N);
    vector<string> listen_watch;
    
    for (int i = 0; i < N; i++) {
        cin >> not_heard[i];
    }
    
    sort(not_heard.begin(), not_heard.end());
    
    for (int i = 0; i < M; i++) {
        string name;
        cin >> name;
        if (binary_search(not_heard.begin(), not_heard.end(), name)) {
            listen_watch.push_back(name);
        }
    }
    
    sort(listen_watch.begin(), listen_watch.end());
    
    cout << listen_watch.size() << '\n';
    for (const string &name : listen_watch) {
        cout << name << '\n';
    }
    
    return 0;
}