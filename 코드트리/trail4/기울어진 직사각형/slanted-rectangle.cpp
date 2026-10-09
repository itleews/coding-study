#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[] = { -1, -1,  1, 1 };
const int dy[] = {  1, -1, -1, 1 };

int n;
vector<vector<int>> grid;

int getScore(int r, int c, int w, int h)
{
    int moveNum[] = { w, h, w, h };

    int sum = 0;
    int cx = r, cy = c;

    for (int d = 0; d < 4; d++)
    {
        for (int step = 0; step < moveNum[d]; step++)
        {
            cx += dx[d];
            cy += dy[d];

            if (cx < 0 || cx >= n || cy < 0 || cy >= n)
                return 0;

            sum += grid[cx][cy];
        }
    }

    return sum;
}

int main()
{
    cin >> n;
    grid.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    int maxScore = 0;
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            for (int w = 1; w < n; w++)
            {
                for (int h = 1; h < n; h++)
                {
                    maxScore = max(maxScore, getScore(r, c, w, h));
                }
            }
        }
    }
    cout << maxScore;
    return 0;
}