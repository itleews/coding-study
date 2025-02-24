#include <iostream>
using namespace std;

void sort(int &a, int &b, int &c) {
    int temp;
    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }
    
    if (b > c) {
        temp = b;
        b = c;
        c = temp;
    }
    
    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }
}

bool isPythagoras(int a, int b, int c) {
    return a * a + b * b == c * c;
}

int main() {
    do {
        int a, b, c;
        cin >> a >> b >> c;
        
        if (a == 0 && b == 0 && c == 0) break;
        
        sort (a, b, c);
        if (isPythagoras(a, b, c)) {
            cout << "right" << endl;
        }
        else {
            cout << "wrong" << endl;
        }
    }
    while (1);
}