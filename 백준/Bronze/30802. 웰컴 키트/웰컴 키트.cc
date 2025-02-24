#include <iostream>
using namespace std;

int main() {
    int N;
    int S, M, L, XL, XXL, XXXL;
    int T, P;
    
    cin >> N;
    cin >> S >> M >> L >> XL >> XXL >> XXXL;
    cin >> T >> P;
    
    int tshirt = (S + T - 1) / T + (M + T - 1) / T + (L + T - 1) / T +
             (XL + T - 1) / T + (XXL + T - 1) / T + (XXXL + T - 1) / T;

    cout << tshirt << endl;
    cout << N / P << " " << N % P << endl;
}