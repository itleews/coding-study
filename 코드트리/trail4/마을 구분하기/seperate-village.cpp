#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int n;
vector<vector<int>> grid;
vector<vector<bool>> visited;

vector<int> person;

int Village(int& curX, int& curY)
{
    queue<pair<int, int>> q;
    q.push({ curX, curY });
    visited[curX][curY] = true;

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

            if (grid[nx][ny] == 0)
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
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1 && !visited[i][j])
            {
                person.push_back(Village(i, j));
            }
        }
    }

    cout << person.size() << "\n";
    
    sort(person.begin(), person.end());

    for (int p : person)
    {
        cout << p << "\n";
    }

    return 0;
}