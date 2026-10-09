#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> grid;

int GetSum(int x1, int y1, int x2, int y2)
{
    int sum = 0;

    for (int i = x1; i <= x2; i++)
    {
        for (int j = y1; j <= y2; j++)
        {
            sum += grid[i][j];
        }
    }

    return sum;
}

bool IsOverlapped(int x1, int y1, int x2, int y2, int a1, int b1, int a2, int b2)
{
    vector<vector<int>> board(n, vector<int>(m, 0));
    
    for (int i = x1; i <= x2; i++)
    {
        for (int j = y1; j <= y2; j++)
        {
            board[i][j]++;
        }
    }

    for (int i = a1; i <= a2; i++)
    {
        for (int j = b1; j <= b2; j++)
        {
            board[i][j]++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] >= 2)
                return true;
        }
    }

    return false;
}

int FindMaxSum(int x1, int y1, int x2, int y2)
{
    int maxVal = -1e9;

    for (int a1 = 0; a1 < n; a1++)
    {
        for (int b1 = 0; b1 < m; b1++)
        {
            for (int a2 = a1; a2 < n; a2++)
            {
                for (int b2 = b1; b2 < m; b2++)
                {
                    if (!IsOverlapped(x1, y1, x2, y2, a1, b1, a2, b2))
                    {
                        int sum1 = GetSum(x1, y1, x2, y2);
                        int sum2 = GetSum(a1, b1, a2, b2);
                        maxVal = max(maxVal, sum1 + sum2);
                    }
                }
            }
        }
    }

    return maxVal;
}

int main()
{
    cin >> n >> m;
    grid.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    int ans = -1e9;

    for (int x1 = 0; x1 < n; x1++)
    {
        for (int y1 = 0; y1 < m; y1++)
        {
            for (int x2 = x1; x2 < n; x2++)
            {
                for (int y2 = y1; y2 < m; y2++)
                {
                    ans = max(ans, FindMaxSum(x1, y1, x2, y2));
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}