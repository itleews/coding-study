#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[] = { -1, -2, -2, -1,  1,  2, 2, 1 };
const int dy[] = { -2, -1,  1,  2, -2, -1, 1, 2 };

int n;
vector<vector<int>> grid;

void Move(int& startX, int& startY, int& endX, int& endY)
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
            cout << dist[cx][cy];
            return;
        }

        for (int i = 0; i < 8; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;

            if (dist[nx][ny] != -1)
                continue;

            dist[nx][ny] = dist[cx][cy] + 1;
            q.push({ nx, ny });
        }
    }

    cout << -1;
}

int main()
{
    cin >> n;
    grid.resize(n, vector<int>(n));

    int startX, startY, endX, endY;
    cin >> startX >> startY >> endX >> endY;

    Move(--startX, --startY, --endX, --endY);
    return 0;
}