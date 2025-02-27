#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    int* num = new int[N];
    
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    
    sort(num, num + N);
    
    for (int i = 0; i < N; i++) {
        cout << num[i] << '\n';
    }
    
    delete[] num;
    return 0;
}