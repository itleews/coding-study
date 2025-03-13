#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int* time = new int[N];
    
    for (int i = 0; i < N; i++) {
        cin >> time[i];
    }
    
    sort(time, time + N);
    
    int sum = 0;
    int prefix_sum = 0;
    for (int i = 0; i < N; i++) {
        prefix_sum += time[i];
        sum += prefix_sum;
    }
    
    cout << sum;
    delete[] time;
    return 0;
}