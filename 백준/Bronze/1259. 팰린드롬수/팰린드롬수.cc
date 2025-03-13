#include <iostream>
using namespace std;

int main() {
    while(1) {
        int num;
        cin >> num;
        if (num == 0) break;
        
        int original_num = num;
        int rev = 0;
        while (num > 0) {
            rev = rev * 10 + (num % 10);
            num /= 10;
        }
        
        if (original_num == rev) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }
    
    return 0;
}