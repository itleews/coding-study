#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    unordered_map<string, string> sitePW;
    
    for (int i = 0; i < N; i++) {
        string site, pw;
        cin >> site >> pw;
        sitePW[site] = pw;
    }
    
    for (int i = 0; i < M; i++) {
        string findSite;
        cin >> findSite;
        cout << sitePW[findSite] << '\n';
    }
    
    return 0;
}