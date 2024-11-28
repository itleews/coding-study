#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int basket[100];
    for(int a = 1; a <= n; a++) {
        basket[a] = a;
    }
    for(int a = 1; a <= m; a++) {
        int i, j;
        cin >> i >> j;
        for(i; i < j; i++ && j--) {
            int change = basket[i];
            basket[i] = basket[j];
            basket[j] = change;
        }
    }
    for(int a = 1; a <= n; a++) {
        cout << basket[a] << " ";
    }
}