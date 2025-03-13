#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    stack<int> st;
    
    while (N--) {
        string cmd;
        cin >> cmd;
        
        if (cmd == "push") {
            int X;
            cin >> X;
            st.push(X);
        }
        else if (cmd == "pop") {
            if (st.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << st.top() << '\n';
                st.pop();
            }
        }
        else if (cmd == "size") {
            cout << st.size() << '\n';
        }
        else if (cmd == "empty") {
            cout << (st.empty() ? 1 : 0) << '\n';
        }
        else if (cmd == "top") {
            if (st.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << st.top() << '\n';
            }
        }
    }
    return 0;
}