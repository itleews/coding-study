#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N;
    int* A = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    // 배열 정렬
    sort(A, A + N);
    
    cin >> M;
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        cout << binary_search(A, A + N, x) << '\n';
    }
    
    delete[] A;
    return 0;
}