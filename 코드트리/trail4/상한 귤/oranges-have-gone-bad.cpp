#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int n, k;
vector<vector<int>> grid;
vector<vector<int>> dist;

vector<pair<int, int>> badMandarin;

void Mandarin()
{
    dist.resize(n, vector<int>(n, -1));

    queue<pair<int, int>> q;
    for (auto& m : badMandarin)
    {
        q.push(m);
        dist[m.first][m.second] = 0;
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

            if (dist[nx][ny] != -1)
                continue;

            if (grid[nx][ny] == 0)
                continue;

            dist[nx][ny] = dist[cx][cy] + 1;
            q.push({ nx, ny });
        }
    }
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

            if (grid[i][j] == 2)
                badMandarin.push_back({ i, j });
        }
    }

    Mandarin();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 0)
            {
                cout << -1 << " ";
            }
            else
            {
                if (dist[i][j] == -1)
                {
                    cout << -2 << " ";
                }
                else
                {
                    cout << dist[i][j] << " ";
                }
            }
        }

        cout << "\n";
    }

    return 0;
}