#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int weight[50], height[50];
    for (int i = 0; i < N; i++) {
        cin >> weight[i] >> height[i];
    }
    
    for (int i = 0; i < N; i++) {
        int rank = 1;
        
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            
            if (weight[i] < weight[j] && height[i] < height[j]) {
                rank++;
            }
        }
        
        cout << rank << " ";
    }
    
    return 0;
}