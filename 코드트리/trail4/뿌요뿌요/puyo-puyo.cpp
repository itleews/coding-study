#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int n;
vector<vector<int>> grid;
vector<vector<bool>> visited;

int Block(int& cx, int& cy)
{
    queue<pair<int, int>> q;
    q.push({ cx, cy });
    visited[cx][cy] = true;
    int value = grid[cx][cy];

    int count = 1;
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

            if (visited[nx][ny])
                continue;

            if (grid[nx][ny] != value)
                continue;

            count++;
            q.push({ nx, ny });
            visited[nx][ny] = true;
        }
    }

    return count;
}

int main()
{
    cin >> n;
    grid.resize(n, vector<int>(n));
    visited.resize(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    int popCount = 0, maxBlock = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j])
                continue;

            int curBlock = Block(i, j);
            maxBlock = max(maxBlock, curBlock);
            if (curBlock >= 4)
            {
                popCount++;
            }
        }
    }

    cout << popCount << " " << maxBlock;
    return 0;
}