#include <iostream>
using namespace std;

long long at(int a, int b) {
    return ((a + b) * (a - b));
}

int main() {
    long long A, B;
    cin >> A >> B;
    cout << at(A, B) << endl;
    return 0;
}