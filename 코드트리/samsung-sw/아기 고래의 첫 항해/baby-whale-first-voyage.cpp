#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Whale
{
    int x, y;
    int d;
};
Whale whale;
vector<vector<int>> Board;
int N = 0;

int dx[] = { 0, -1, 1, 0, 0 }; // 1: 상, 2: 하, 3: 좌, 4: 우
int dy[] = { 0, 0, 0, -1, 1 };

int NextDir(int curDir, int turnType)
{
    int dirMap[5][4] = // 직진(0), 좌회전(1), 우회전(2), 후진(3)
    {
        { 0, 0, 0, 0 },
        { 1, 3, 4, 2 }, // 상
        { 2, 4, 3, 1 }, // 하
        { 3, 2, 1, 4 }, // 좌
        { 4, 1, 2, 3 }, // 우
    };

    return dirMap[curDir][turnType];
}

bool MoveNormal()
{
    // 0: 직진, 1: 좌회전, 2: 우회전, 3: 후진
    for (int i = 0; i < 4; i++)
    {
        int nDir = NextDir(whale.d, i);
        int nx = whale.x + dx[nDir];
        int ny = whale.y + dy[nDir];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
            continue;

        if (Board[nx][ny] == 1)
            continue;

        if (Board[nx][ny] == 0)
        {
            whale.x = nx;
            whale.y = ny;
            whale.d = nDir;
            Board[nx][ny] = 2;
            cout << nx + 1 << " " << ny + 1 << "\n";
            return true;
        }
    }

    return false;
}

bool FindAnotherRoot()
{
    // 고립 상태일 때 다른 길 찾기
    vector<vector<int>> dist(N, vector<int>(N, -1));
    queue<pair<int, int>> q;

    // 1. 아직 0인 길 찾기
    q.push({ whale.x, whale.y });
    dist[whale.x][whale.y] = 0;

    int targetX = -1, targetY = -1;
    int minDist = 99999;

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 1; i <= 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;

            if (Board[nx][ny] == 1)
                continue;

            if (dist[nx][ny] != -1)
                continue;

            dist[nx][ny] = dist[cx][cy] + 1;
            q.push({ nx, ny });

            if (Board[nx][ny] == 0)
            {
                if (dist[nx][ny] < minDist)
                {
                    minDist = dist[nx][ny];
                    targetX = nx;
                    targetY = ny;
                }
                else if (dist[nx][ny] == minDist)
                {
                    if (nx < targetX || (nx == targetX && ny < targetY))
                    {
                        targetX = nx;
                        targetY = ny;
                    }
                }
            }
        }
    }

    if (targetX == -1)
        return false;

    // 2. 목표 지점으로부터 최단거리 찾기
    vector<vector<int>> revDist(N, vector<int>(N, -1));
    queue<pair<int, int>> rq;
    rq.push({ targetX, targetY });
    revDist[targetX][targetY] = 0;

    while (!rq.empty())
    {
        int cx = rq.front().first;
        int cy = rq.front().second;
        rq.pop();

        for (int i = 1; i <= 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;

            if (Board[nx][ny] == 1)
                continue;

            if (revDist[nx][ny] != -1)
                continue;

            revDist[nx][ny] = revDist[cx][cy] + 1;
            rq.push({ nx, ny });
        }
    }

    // 3. 좌, 하, 우, 상 순서로 이동
    int order[] = { 3, 2, 4, 1 };

    while (whale.x != targetX || whale.y != targetY)
    {
        int curDist = revDist[whale.x][whale.y];

        for (int i = 0; i < 4; i++)
        {
            int dir = order[i];
            int nx = whale.x + dx[dir];
            int ny = whale.y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;

            if (Board[nx][ny] == 1)
                continue;

            if (revDist[nx][ny] == curDist - 1)
            {
                whale.x = nx;
                whale.y = ny;
                whale.d = dir;
                Board[nx][ny] = 2;
                break;
            }
        }
    }

    cout << whale.x + 1 << " " << whale.y + 1 << "\n";
    return true;
}

int main(int argc, char** argv)
{
    cin >> N >> whale.x >> whale.y >> whale.d;
    whale.x--; whale.y--;

    Board.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> Board[i][j];
        }
    }

    cout << whale.x + 1 << " " << whale.y + 1 << "\n";
    Board[whale.x][whale.y] = 2;

    while (true)
    {
        // 1단계: 인접 탐색
        if (!MoveNormal())
        {
            // 2단계: 고립 시 점프 탐색
            if (!FindAnotherRoot())
            {
                break;
            }
        }
    }

    return 0;
}