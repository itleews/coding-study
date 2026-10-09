#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int n, m;
vector<vector<int>> grid;
vector<pair<int, int>> ice;

bool Melt()
{
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    queue<pair<int, int>> q;
    q.push({ 0, 0 });
    visited[0][0] = true;

    while (!q.empty())
    {
        auto [cx, cy] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if (visited[nx][ny])
                continue;

            if (grid[nx][ny] == 0)
            {
                q.push({ nx, ny });
                visited[nx][ny] = true;
            }
            else if (grid[nx][ny] == 1)
            {
                ice.push_back({ nx, ny });
                visited[nx][ny] = true;
            }
        }
    }

    if (ice.size() == 0)
        return false;

    for (auto& i : ice)
    {
        grid[i.first][i.second] = 0;
    }

    return true;
}

int main()
{
    cin >> n >> m;
    grid.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    int time = 0, lastIceSize = 0;
    while (true)
    {
        if (!Melt())
            break;

        time++;
        lastIceSize = static_cast<int>(ice.size());
        ice.clear();
    }

    cout << time << " " << lastIceSize;
    return 0;
}