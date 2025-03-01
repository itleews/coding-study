#include <iostream>
using namespace std;

int main() {
    int K;
    cin >> K;
    
    int* stack = new int[K];
    int top = 0;
    
    while (K--) {
        int num;
        cin >> num;
        
        if (num == 0 && top > 0) {
            top--;
        }
        else {
            stack[top++] = num;
        }
    }
    
    int sum = 0;
    for (int i = 0; i < top; i++) {
        sum += stack[i];
    }
    
    cout << sum << '\n';
    
    delete[] stack;
    return 0;
}