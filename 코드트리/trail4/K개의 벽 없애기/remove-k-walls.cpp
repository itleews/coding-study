#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int n, k;
vector<vector<int>> grid;

vector<pair<int, int>> walls;
int startX, startY, endX, endY;
int minDist = -1;

int Move()
{
    vector<vector<int>> dist(n, vector<int>(n, -1));

    queue<pair<int, int>> q;
    q.push({ startX, startY });
    dist[startX][startY] = 0;

    while (!q.empty())
    {
        auto [cx, cy] = q.front();
        q.pop();

        if (cx == endX && cy == endY)
        {
            return dist[endX][endY];
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;

            if (dist[nx][ny] != -1)
                continue;

            if (grid[nx][ny] == 1)
                continue;

            dist[nx][ny] = dist[cx][cy] + 1;
            q.push({ nx, ny });
        }
    }

    return -1;
}

void BreakWall(int idx, int breakCount)
{
    if (breakCount == k)
    {
        int d = Move();
        if (d != -1)
        {
            minDist = (minDist == -1) ? d : min(minDist, d);
        }
        return;
    }

    if (idx >= walls.size())
        return;

    auto [x, y] = walls[idx];
    grid[x][y] = 0;
    BreakWall(idx + 1, breakCount + 1);

    grid[x][y] = 1;
    BreakWall(idx + 1, breakCount);
}

int main()
{
    cin >> n >> k;
    grid.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];

            if (grid[i][j] == 1)
            {
                walls.push_back({ i, j });
            }
        }
    }

    cin >> startX >> startY;
    cin >> endX >> endY;
    --startX; --startY; --endX; --endY;

    BreakWall(0, 0);

    cout << minDist;
    return 0;
}