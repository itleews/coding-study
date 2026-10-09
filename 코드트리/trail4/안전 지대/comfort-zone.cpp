#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int n, m;
vector<vector<int>> grid;
vector<vector<bool>> visited;

void FindSafeArea(int& cx, int& cy, int& k)
{
    visited[cx][cy] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = cx + dx[i];
        int ny = cy + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;

        if (visited[nx][ny])
            continue;

        if (grid[nx][ny] <= k)
            continue;

        FindSafeArea(nx, ny, k);
    }
}

int main()
{
    cin >> n >> m;
    grid.resize(n, vector<int>(m));

    int maxHeight = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int height;
            cin >> height;
            
            grid[i][j] = height;
            maxHeight = max(maxHeight, height);
        }
    }

    int bestK = 1, bestCount = 0;
    for (int k = 1; k <= maxHeight; k++)
    {
        visited.clear();
        visited.resize(n, vector<bool>(m, false));

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visited[i][j] || grid[i][j] <= k)
                    continue;

                FindSafeArea(i, j, k);
                count++;
            }
        }

        if (bestCount < count)
        {
            bestCount = count;
            bestK = k;
        }
    }

    cout << bestK << " " << bestCount;
    return 0;
}