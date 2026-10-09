#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int n, k, l;
vector<vector<int>> grid;
vector<pair<int, int>> cleaner;

void MoveCleaner()
{
    for (int idx = 0; idx < k; idx++)
    {
        vector<vector<bool>> hasOtherCleaner(n, vector<bool>(n, false));
        for (int i = 0; i < k; i++)
        {
            if (i == idx)
                continue;

            hasOtherCleaner[cleaner[i].first][cleaner[i].second] = true;
        }

        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        int startX = cleaner[idx].first;
        int startY = cleaner[idx].second;
        q.push({ startX, startY });
        dist[startX][startY] = 0;

        while (!q.empty())
        {
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;

                if (dist[nx][ny] != -1)
                    continue;

                if (grid[nx][ny] == -1)
                    continue;

                if (hasOtherCleaner[nx][ny])
                    continue;

                dist[nx][ny] = dist[cx][cy] + 1;
                q.push({ nx, ny });
            }
        }

        int targetX = -1, targetY = -1;
        int minDist = 1e9;

        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (grid[r][c] <= 0 || dist[r][c] == -1)
                    continue;
                
                if (dist[r][c] < minDist)
                {
                    minDist = dist[r][c];
                    targetX = r;
                    targetY = c;
                }
            }
        }

        if (targetX != -1)
        {
            cleaner[idx] = { targetX, targetY };
        }
    }
}

// 우, 하, 좌, 상
const int cdx[] = { 0, 1, 0, -1 };
const int cdy[] = { 1, 0, -1, 0 };

int GetCleanableAmout(int r, int c)
{
    if (r < 0 || r >= n || c < 0 || c >= n)
        return 0;

    if (grid[r][c] <= 0)
        return 0;

    return min(grid[r][c], 20);
}

void Clean()
{
    for (int idx = 0; idx < k; idx++)
    {
        int cr = cleaner[idx].first;
        int cc = cleaner[idx].second;

        int bestDir = -1;
        int maxCleanSum = -1;

        for (int d = 0; d < 4; d++)
        {
            int sum = 0;

            // 현재 위치
            sum += GetCleanableAmout(cr, cc);

            // 앞 칸
            sum += GetCleanableAmout(cr + cdx[d], cc + cdy[d]);

            // 왼쪽 칸
            int leftDir = (d + 3) % 4;
            sum += GetCleanableAmout(cr + cdx[leftDir], cc + cdy[leftDir]);

            // 오른쪽 칸
            int rightDir = (d + 1) % 4;
            sum += GetCleanableAmout(cr + cdx[rightDir], cc + cdy[rightDir]);

            if (sum > maxCleanSum)
            {
                maxCleanSum = sum;
                bestDir = d;
            }
        }

        if (bestDir != -1)
        {
            vector<pair<int, int>> cleanCoords =
            {
                {cr, cc},
                { cr + cdx[bestDir], cc + cdy[bestDir] },
                { cr + cdx[(bestDir + 3) % 4], cc + cdy[(bestDir + 3) % 4] },
                { cr + cdx[(bestDir + 1) % 4], cc + cdy[(bestDir + 1) % 4] }
            };

            for (const auto& [tr, tc] : cleanCoords)
            {
                if (tr < 0 || tr >= n || tc < 0 || tc >= n)
                    continue;

                if (grid[tr][tc] <= 0)
                    continue;

                int cleanVal = min(grid[tr][tc], 20);
                grid[tr][tc] -= cleanVal;
            }
        }
    }
}

void AddDust()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] > 0)
            {
                grid[i][j] += 5;
            }
        }
    }
}

void SpreadDust()
{
    vector<vector<int>> nextGrid = grid;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 0)
            {
                int sum = 0;

                for (int d = 0; d < 4; d++)
                {
                    int nx = i + dx[d];
                    int ny = j + dy[d];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        continue;

                    if (grid[nx][ny] > 0)
                    {
                        sum += grid[nx][ny];
                    }
                }

                nextGrid[i][j] = sum / 10;
            }
        }
    }

    grid = nextGrid;
}

bool Test()
{
    // 1. 청소기 이동
    MoveCleaner();

    // 2. 청소
    Clean();

    // 3. 먼지 축적
    AddDust();

    // 4. 먼지 확산
    SpreadDust();

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == -1)
                continue;
            
            sum += grid[i][j];
        }
    }

    cout << sum << "\n";

    if (sum == 0)
        return false;
    else
        return true;
}

int main()
{
    cin >> n >> k >> l;
    grid.resize(n, vector<int>(n));
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < k; i++)
    {
        int r, c;
        cin >> r >> c;
        cleaner.push_back({ --r, --c });
    }

    for (int i = 0; i < l; i++)
    {
        if (!Test())
            break;
    }

    return 0;
}