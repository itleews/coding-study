#include <iostream>
using namespace std;

int N, M;
char** board;

/// 체스판 패턴과 비교하여 다시 칠해야 하는 개수 반환
int countRepaint(int x, int y) {
    int cntW = 0, cntB = 0;
    char chessW[8][8] = {
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'}
    };
    
    // 8*8 영역 검사
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[x + i][y + j] != chessW[i][j]) cntW++; // W 시작 체스판
            if (board[x + i][y + j] != (chessW[i][j] == 'W' ? 'B' : 'W')) cntB++; // B 시작 체스판
        }
    }
    
    return min(cntW, cntB);
}

int main() {
    cin >> N >> M;
    
    board = new char*[N];
    for (int i = 0; i < N; i++) {
        board[i] = new char[M];
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    
    int minRepaint = 64; // 최악의 경우(모두 바뀌는 경우)
    
    // 8*8 시작점 탐색
    for (int i = 0; i <= N - 8; i++) {
        for (int j = 0; j <= M - 8; j++) {
            minRepaint = min(minRepaint, countRepaint(i, j));
        }
    }
    
    cout << minRepaint << endl;
    
    for (int i = 0; i < N; i++) {
        delete[] board[i];
    }
    delete[] board;
    return 0;
}