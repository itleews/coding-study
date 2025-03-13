#include <iostream>
using namespace std;

int main() {
    int A, B, V;
    cin >> A >> B >> V;
    
    int day = (V - A) / (A - B);
    
    if ((V - A) % (A - B) != 0) {
        day++;
    }
    day++;
    
    cout << day << endl;
    return 0;
}