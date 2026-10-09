#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int n, k, u, d;
int maxCount = 0;

vector<vector<int>> grid;
vector<pair<int, int>> selectedCities;

int City()
{
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    queue<pair<int, int>> q;

    for (auto& city : selectedCities)
    {
        q.push({ city.first, city.second });
        visited[city.first][city.second] = true;
    }

    int count = static_cast<int>(selectedCities.size());
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

            int diff = abs(grid[nx][ny] - grid[cx][cy]);
            if (diff < u || diff > d)
                continue;

            q.push({ nx, ny });
            visited[nx][ny] = true;
            count++;
        }
    }

    return count;
}

void Select(int idx, int pickedCount)
{
    if (pickedCount == k)
    {
        maxCount = max(maxCount, City());
        return;
    }

    if (idx >= n * n)
        return;

    int r = idx / n;
    int c = idx % n;
    selectedCities.push_back({ r, c });
    Select(idx + 1, pickedCount + 1);

    selectedCities.pop_back();
    Select(idx + 1, pickedCount);
}

int main()
{
    cin >> n >> k >> u >> d;
    grid.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    Select(0, 0);
    cout << maxCount;
    return 0;
}