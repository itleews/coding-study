#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    char* str = new char[N];
    for (int i = 0; i < N; i++) {
        cin >> str[i];
        str[i] = str[i] - 'a' + 1;
    }
    
    int hash = 0;
    
    for (int i = 0; i < N; i++) {
        hash += str[i] * pow(31, i);
    }
    
    cout << hash << endl;
    
    delete[] str;
}