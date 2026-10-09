#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int n, k;
vector<vector<int>> grid;

bool Move(int& curX, int& curY)
{
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<pair<int, int>> q;

    q.push({ curX, curY });
    visited[curX][curY] = true;
    
    int startValue = grid[curX][curY];

    int bestVal = -1;
    int bestX = -1;
    int bestY = -1;

    while (!q.empty())
    {
        auto [cx, cy] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;

            if (visited[nx][ny] || grid[nx][ny] >= startValue)
                continue;

            q.push({ nx, ny });
            visited[nx][ny] = true;

            int nVal = grid[nx][ny];

            // 목적지 우선순위 갱신
            if (nVal > bestVal)
            {
                bestVal = nVal;
                bestX = nx;
                bestY = ny;
            }
            else if (nVal == bestVal)
            {
                if (nx < bestX)
                {
                    bestX = nx;
                    bestY = ny;
                }
                else if (nx == bestX && ny < bestY)
                {
                    bestY = ny;
                }
            }
        }
    }

    if (bestVal == -1)
        return false;

    curX = bestX;
    curY = bestY;
    return true;
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
        }
    }

    int curX, curY;
    cin >> curX >> curY;
    --curX; --curY;

    for (int step = 0; step < k; step++)
    {
        if (!Move(curX, curY))
            break;
    }

    cout << curX + 1 << " " << curY + 1 << "\n";
    return 0;
}