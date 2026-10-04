#include <iostream>
#include <vector>
using namespace std;

struct Ball
{
    int r;
    int c;
};

pair<int, int> findNextPosition(int r, int c, const vector<vector<int>>& grid, int n)
{
    const int dx[4] = { -1, 1, 0, 0 };
    const int dy[4] = { 0, 0, -1, 1 };

    int maxValue = -1;
    int nextR = r;
    int nextC = c;

    for (int d = 0; d < 4; d++)
    {
        int nr = r + dx[d];
        int nc = c + dy[d];

        if (nr < 0 || nr >= n || nc < 0 || nc >= n)
            continue;

        if (grid[nr][nc] > maxValue)
        {
            maxValue = grid[nr][nc];
            nextR = nr;
            nextC = nc;
        }
    }

    return { nextR, nextC };
}

void removeCollisions(vector<Ball>& balls)
{
    vector<Ball> nextBalls;

    for (int i = 0; i < balls.size(); i++)
    {
        bool collision = false;

        for (int j = 0; j < balls.size(); j++)
        {
            if (i != j &&
                balls[i].r == balls[j].r &&
                balls[i].c == balls[j].c)
            {
                collision = true;
                break;
            }
        }

        if (!collision)
            nextBalls.push_back(balls[i]);
    }

    balls = nextBalls;
}

int main()
{
    int n, m, t;
    cin >> n >> m >> t;

    vector<vector<int>> grid(n, vector<int>(n));

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            cin >> grid[r][c];
        }
    }

    vector<Ball> balls(m);

    for (Ball& ball : balls)
    {
        cin >> ball.r >> ball.c;
        --ball.r;
        --ball.c;
    }

    for (int time = 0; time < t; time++)
    {
        for (Ball& ball : balls)
        {
            auto [nextR, nextC] = findNextPosition(ball.r, ball.c, grid, n);

            ball.r = nextR;
            ball.c = nextC;
        }

        removeCollisions(balls);
    }

    cout << balls.size();

    return 0;
}