#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 상, 하, 좌, 우
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

vector<vector<int>> grid;
vector<vector<bool>> visited;

int Found(int startX, int startY)
{
    if (visited[startX][startY] || grid[startX][startY] == 1)
        return 0;

    queue<pair<int, int>> q;
    q.push({ startX, startY });
    visited[startX][startY] = true;

    int count = 1; // 시작점 포함

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid.size())
                continue;

            if (grid[nx][ny] == 1 || visited[nx][ny])
                continue;

            q.push({ nx, ny });
            visited[nx][ny] = true;
            count++;
        }
    }

    return count;
}

int main()
{
    int n, k;
    cin >> n >> k;
    grid.resize(n, vector<int>(n));
    visited.resize(n, vector<bool>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    int totalCount = 0;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        totalCount += Found(--x, --y);
    }

    cout << totalCount;
    return 0;
}