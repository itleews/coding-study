#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    int five = N / 5, three = 0;
    
    if (N % 5 == 0) {
        cout << five << '\n';
        return 0;
    }
    
    while (five >= 0) {
        int remain = N - (five * 5);
        if (remain % 3 == 0) {
            three = remain / 3;
            cout << (five + three) << '\n';
            return 0;
        }
        five--;
    }
    
    cout << "-1\n";
    return 0;
}