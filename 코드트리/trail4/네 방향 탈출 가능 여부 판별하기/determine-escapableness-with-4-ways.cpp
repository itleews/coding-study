#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> board;
vector<vector<bool>> visited;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void BFS(int x, int y)
{
    queue<pair<int, int>> q;

    q.push({ x, y });
    visited[x][y] = true;

    while (!q.empty())
    {
        auto [curX, curY] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if (board[nx][ny] == 0)
                continue;

            if (visited[nx][ny])
                continue;

            visited[nx][ny] = true;
            q.push({ nx, ny });
        }
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

    BFS(0, 0);

    cout << visited[n - 1][m - 1];

    return 0;
}