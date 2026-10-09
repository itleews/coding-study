#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int n, k, m;
vector<vector<int>> grid;
vector<pair<int, int>> stones;
vector<pair<int, int>> startPos;
int maxVisited = 0;

int Calc()
{
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<pair<int, int>> q;
    int count = 0;

    for (auto [r, c] : startPos)
    {
        visited[r][c] = true;
        q.push({ r, c });
        count++;
    }

    while (!q.empty())
    {
        auto [cr, cc] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nr = cr + dx[i];
            int nc = cc + dy[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                continue;

            if (visited[nr][nc] || grid[nr][nc] == 1)
                continue;

            visited[nr][nc] = true;
            q.push({ nr, nc });
            count++;
        }
    }

    return count;
}

void PickStones(int idx, int pickedCount)
{
    if (pickedCount == m)
    {
        maxVisited = max(maxVisited, Calc());
        return;
    }

    if (idx >= stones.size())
        return;

    // 1. 현재 돌을 치우기
    auto [r, c] = stones[idx];
    grid[r][c] = 0;
    PickStones(idx + 1, pickedCount + 1);

    // 2. 돌을 다시 놓고, 안 치우고 넘어가기
    grid[r][c] = 1;
    PickStones(idx + 1, pickedCount);
}

int main()
{
    cin >> n >> k >> m;
    grid.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];

            if (grid[i][j] == 1)
            {
                stones.push_back({ i, j });
            }
        }
    }

    for (int i = 0; i < k; i++)
    {
        int r, c;
        cin >> r >> c;
        startPos.push_back({ --r, --c });
    }

    PickStones(0, 0);

    cout << maxVisited;

    return 0;
}