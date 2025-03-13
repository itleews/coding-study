#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    stack<int> s;
    vector<char> result;
    int current = 1;
    bool possible = true;
    
    for (int i = 0; i < n; i++) {
        int target;
        cin >> target;
        
        while (current <= target) {
            s.push(current++);
            result.push_back('+');
        }
        
        if (!s.empty() && s.top() == target) {
            s.pop();
            result.push_back('-');
        }
        else {
            possible = false;
            break;
        }
    }
    
    if (possible) {
        for (char c : result) {
            cout << c << "\n";
        }
    }
    else {
        cout << "NO\n";
    }
    
    return 0;
}