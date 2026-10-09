#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };

int N, M, K;
vector<vector<int>> grid;
vector<vector<int>> dist;

struct Turtle
{
    int id;
    int r, c;
    bool escapede = false; // 안식처 도착 여부
    bool alive = true;     // 생존 여부
    int arriveTurn = -1;
};
vector<Turtle> turtles;

struct Volcano
{
    int r, c;
    int p;                // 분출 임계치
    int pressure = 0;     // 현재 마그마 압력
    bool erupted = false; // 이번 턴 분출 여부
};
vector<Volcano> volcanoes;

vector<vector<int>> GetDistToShelter(const vector<vector<bool>>& isBlocked)
{
    vector<vector<int>> d(N, vector<int>(N, -1));
    queue<pair<int, int>> q;

    if (!isBlocked[N - 1][N - 1])
    {
        q.push({ N - 1, N - 1 });
        d[N - 1][N - 1] = 0;
    }

    while (!q.empty())
    {
        auto [cx, cy] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;

            if (isBlocked[nx][ny])
                continue;

            if (d[nx][ny] != -1)
                continue;

            d[nx][ny] = d[cx][cy] + 1;
            q.push({ nx, ny });
        }
    }
    return d;
}

void MoveTurtles(int currentTurn)
{
    vector<vector<bool>> isBlocked(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == 1)
            {
                isBlocked[i][j] = true;
            }
        }
    }

    for (const auto& t : turtles)
    {
        if (t.escapede || (t.r == N - 1 && t.c == N - 1))
            continue;

        isBlocked[t.r][t.c] = true;
    }
    isBlocked[N - 1][N - 1] = false;

    for (auto& t : turtles)
    {
        if (!t.alive || t.escapede)
            continue;

        isBlocked[t.r][t.c] = false;

        vector<vector<int>> dMap = GetDistToShelter(isBlocked);

        if (dMap[t.r][t.c] == -1)
        {
            isBlocked[t.r][t.c] = true;
            continue;
        }

        int bestDir = -1;

        for (int d = 0; d < 4; d++)
        {
            int nx = t.r + dx[d];
            int ny = t.c + dy[d];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;

            if (isBlocked[nx][ny])
                continue;

            if (dMap[nx][ny] == dMap[t.r][t.c] - 1)
            {
                bestDir = d;
                break;
            }
        }

        if (bestDir != -1)
        {
            t.r += dx[bestDir];
            t.c += dy[bestDir];

            if (t.r == N - 1 && t.c == N - 1)
            {
                t.escapede = true;
                t.arriveTurn = currentTurn;
                isBlocked[t.r][t.c] = false;
            }
            else
            {
                isBlocked[t.r][t.c] = true;
            }
        }
        else
        {
            isBlocked[t.r][t.c] = true;
        }
    }
}

void SpreadHeat(int vr, int vc, int initialP, vector<vector<int>>& heatMap)
{
    heatMap[vr][vc] += initialP;

    for (int d = 0; d < 4; d++)
    {
        int curHeat = initialP / 2;
        int cr = vr + dx[d];
        int cc = vc + dy[d];

        while (curHeat > 0)
        {
            if (cr < 0 || cr >= N || cc < 0 || cc >= N)
                break;

            if (grid[cr][cc] == 1)
                break;

            heatMap[cr][cc] += curHeat;

            curHeat /= 2;
            cr += dx[d];
            cc += dy[d];
        }
    }
}

void ProcessVolcanoes()
{
    for (auto& v : volcanoes)
    {
        v.pressure += 10;
        v.erupted = false;
    }

    vector<vector<int>> heatMap(N, vector<int>(N, 0));

    while (true)
    {
        bool hasNewEruption = false;

        for (auto& v : volcanoes)
        {
            if (v.erupted)
                continue;

            if (v.pressure + heatMap[v.r][v.c] >= v.p)
            {
                v.erupted = true;
                hasNewEruption = true;
                SpreadHeat(v.r, v.c, v.p, heatMap);
            }
        }

        if (!hasNewEruption)
            break;
    }

    for (auto& t : turtles)
    {
        if (!t.alive || t.escapede)
            continue;

        if (heatMap[t.r][t.c] >= 20)
        {
            t.alive = false;
        }
    }

    for (auto& v : volcanoes)
    {
        if (v.erupted)
        {
            v.pressure = 0;
        }
    }
}

bool HasActiveTurtles()
{
    for (const auto& t : turtles)
    {
        if (t.alive && !t.escapede)
            return true;
    }
    return false;
}

int main()
{
    cin >> N >> M >> K;
    grid.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < M; i++)
    {
        int r, c;
        cin >> r >> c;

        Turtle t;
        t.id = i + 1;
        t.r = r;
        t.c = c;
        turtles.push_back(t);
    }

    for (int i = 0; i < K; i++)
    {
        int r, c, p;
        cin >> r >> c >> p;

        Volcano v;
        v.r = r;
        v.c = c;
        v.p = p;
        volcanoes.push_back(v);
    }

    for (int turn = 1; turn <= 100; turn++)
    {
        if (!HasActiveTurtles())
            break;

        MoveTurtles(turn);

        ProcessVolcanoes();
    }

    for (const auto& t : turtles)
    {
        cout << t.arriveTurn << "\n";
    }

    return 0;
}