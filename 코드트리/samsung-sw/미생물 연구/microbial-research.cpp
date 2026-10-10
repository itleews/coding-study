#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int n, q;
vector<vector<int>> grid;

struct Micro
{
    int id;
    int size;       // 칸 수 (크기)
    int spawnTurn;  // 투입된 시점
    vector<pair<int, int>> relativeCells; // (0, 0) 기준 상대 좌표들
};
vector<Micro> micro;

void InsertMicro(int id, int r1, int c1, int r2, int c2)
{
    for (int i = r1; i < r2; i++)
    {
        for (int j = c1; j < c2; j++)
        {
            grid[i][j] = id;
        }
    }
}

void CheckSplits()
{
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<int> componentCount(q + 1, 0);
    vector<int> totalCellCount(q + 1, 0);

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (grid[r][c] <= 0)
                continue;

            totalCellCount[grid[r][c]]++;
        }
    }

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            int id = grid[r][c];

            if (id <= 0 || visited[r][c])
                continue;

            componentCount[id]++;

            queue<pair<int, int>> q;
            q.push({ r, c });
            visited[r][c] = true;

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

                    if (visited[nr][nc])
                        continue;

                    if (grid[nr][nc] != id)
                        continue;

                    visited[nr][nc] = true;
                    q.push({ nr, nc });
                }
            }
        }
    }

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            int& id = grid[r][c];
            if (id > 0 && componentCount[id] > 1)
            {
                id = 0;
            }
        }
    }
}

bool CanPlace(const vector<pair<int, int>>& cells, int baseR, int baseC, const vector<vector<int>>& newGrid)
{
    for (auto [dr, dc] : cells)
    {
        int nr = baseR + dr;
        int nc = baseC + dc;
        if (nr < 0 || nr >= n || nc < 0 || nc >= n)
            return false;

        if (newGrid[nr][nc] != 0)
            return false;
    }
    return true;
}

void MoveAll()
{
    vector<vector<pair<int, int>>> cellsById(q + 1);
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (grid[r][c] > 0)
            {
                cellsById[grid[r][c]].push_back({ r, c });
            }
        }
    }

    vector<Micro> liveList;
    for (int id = 1; id <= q; id++)
    {
        if (cellsById[id].empty())
            continue;

        int minR = n, minC = n;
        for (auto [r, c] : cellsById[id])
        {
            minR = min(minR, r);
            minC = min(minC, c);
        }

        vector<pair<int, int>> relCells;
        for (auto [r, c] : cellsById[id])
        {
            relCells.push_back({ r - minR, c - minC });
        }

        liveList.push_back({ id, static_cast<int>(relCells.size()), id, relCells });
    }

    sort(liveList.begin(), liveList.end(), [](const Micro& a, const Micro& b)
    {
        if (a.size != b.size)
            return a.size > b.size;

        return a.spawnTurn < b.spawnTurn;
    });

    vector<vector<int>> newGrid(n, vector<int>(n, 0));

    for (const auto& m : liveList)
    {
        bool placed = false;

        for (int r = 0; r < n && !placed; r++)
        {
            for (int c = 0; c < n && !placed; c++)
            {
                if (CanPlace(m.relativeCells, r, c, newGrid))
                {
                    for (auto [dr, dc] : m.relativeCells)
                    {
                        newGrid[r + dr][c + dc] = m.id;
                    }
                    placed = true;
                }
            }
        }
    }

    grid = newGrid;
}

void GetScore()
{
    set<pair<int, int>> adjPairs;
    vector<int> microSize(q + 1, 0);

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            int curId = grid[r][c];
            if (curId <= 0)
                continue;

            microSize[curId]++;

            for (int d = 0; d < 4; d++)
            {
                int nr = r + dx[d];
                int nc = c + dy[d];

                if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                    continue;

                int nextId = grid[nr][nc];
                if (nextId > 0 && nextId != curId)
                {
                    adjPairs.insert({ min(curId, nextId), max(curId, nextId) });
                }
            }
        }
    }

    long long totalScore = 0;
    for (auto [u, v] : adjPairs)
    {
        totalScore += 1LL * microSize[u] * microSize[v];
    }

    cout << totalScore << "\n";
}

int main()
{
    cin >> n >> q;
    grid.resize(n, vector<int>(n, 0));

    for (int turn = 1; turn <= q; turn++)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        // 1. 새 미생물 투입 (turn 번호를 ID로 부여)
        InsertMicro(turn, r1, c1, r2, c2);

        // 2. 쪼개진 미생물 소멸 검사
        CheckSplits();

        // 3. 새 배양 용기로 이동 및 재배치
        MoveAll();

        // 4. 점수 계산 및 출력
        GetScore();
    }

    return 0;
}