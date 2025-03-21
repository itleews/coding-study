#include <iostream>
#include <string>
using namespace std;

int main() {
    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    long long mul = a * b * c;
    string mulStr = to_string(mul);
    
    int count[10] = {0};
    
    for (char ch : mulStr) {
        count[ch - '0']++;
    }
    
    for (int i = 0; i < 10; i++) {
        cout << count[i] << endl;
    }
    
    return 0;
}