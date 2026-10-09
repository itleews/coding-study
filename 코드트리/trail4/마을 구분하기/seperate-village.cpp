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
int currenVillageSize = 0;

void Village(int& curX, int& curY)
{
    visited[curX][curY] = true;
    currenVillageSize++;

    for (int i = 0; i < 4; i++)
    {
        int nx = curX + dx[i];
        int ny = curY + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;

        if (visited[nx][ny] || grid[nx][ny] == 0)
            continue;

        Village(nx, ny);
    }
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
                currenVillageSize = 0;
                Village(i, j);
                person.push_back(currenVillageSize);
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