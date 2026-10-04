#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> board;
vector<vector<bool>> visited;

int dx[] = { 0, 1 };
int dy[] = { 1, 0 };

void DFS(int x, int y)
{
    visited[x][y] = true;

    for (int dir = 0; dir < 2; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;

        if (board[nx][ny] == 0)
            continue;

        if (visited[nx][ny])
            continue;

        DFS(nx, ny);
    }
}

int main()
{
    cin >> n >> m;

    board.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    DFS(0, 0);

    cout << visited[n - 1][m - 1];

    return 0;
}