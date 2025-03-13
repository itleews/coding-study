#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int M, bit = 0;
    cin >> M;
    
    while (M--) {
        string op;
        int x;
        cin >> op;
        
        if (op == "add") {
            cin >> x;
            bit |= (1 << x);
        }
        else if (op == "remove") {
            cin >> x;
            bit &= ~(1 << x);
        }
        else if (op == "check") {
            cin >> x;
            cout << ((bit & (1 << x)) ? 1 : 0) << '\n';
        }
        else if (op == "toggle") {
            cin >> x;
            bit ^= (1 << x);
        }
        else if (op == "all") {
            bit = (1 << 21) - 1;
        }
        else if (op == "empty") {
            bit = 0;
        }
    }
    
    return 0;
}