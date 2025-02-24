#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;
    
    for (int i = 0; i < str.length(); i++) {
        if ('A' <= str[i] && str[i] <= 'Z') {
            str[i] += 32;
            cout << str[i];
        } else {
            str[i] -= 32;
            cout << str[i];
        }
    }
    return 0;
}