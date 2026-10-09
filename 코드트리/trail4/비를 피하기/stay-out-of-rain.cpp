#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int n, h, m;
vector<vector<int>> grid;
vector<vector<int>> result;

vector<pair<int, int>> human;
vector<pair<int, int>> shelter;

void FindShelter()
{
    result.resize(n, vector<int>(n, -1));

    queue<pair<int, int>> q;
    for (pair<int, int> s : shelter)
    {
        q.push(s);
        result[s.first][s.second] = 0;
    }

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

            if (grid[nx][ny] == 1)
                continue;

            if (result[nx][ny] != -1)
                continue;

            result[nx][ny] = result[cx][cy] + 1;
            q.push({ nx, ny });
        }
    }

}

int main()
{
    cin >> n >> h >> m;
    grid.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];

            if (grid[i][j] == 3)
            {
                shelter.push_back({ i, j });
            }
        }
    }

    FindShelter();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 2)
            {
                cout << result[i][j] << " ";
            }
            else
            {
                cout << 0 << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}