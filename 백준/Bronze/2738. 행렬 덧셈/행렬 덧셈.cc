#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int N2 = N * 2;
    int** matrix = new int*[N2];
    for (int i = 0; i < N2; i++) {
        matrix[i] = new int[M];
    }

    for (int i = 0; i < N2; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << matrix[i][j] + matrix[i + N][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < N2; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}