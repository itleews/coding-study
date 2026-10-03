#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    int happy = 0;

    // 가로
    for (int x = 0; x < n; x++)
    {
        int count = 1;
        bool isHappy = (m == 1);

        for (int y = 0; y < n - 1; y++)
        {
            if (grid[x][y] == grid[x][y + 1])
            {
                count++;

                if (count >= m)
                    isHappy = true;
            }
            else
            {
                count = 1;
            }
        }

        if (isHappy)
            happy++;
    }

    // 세로
    for (int y = 0; y < n; y++)
    {
        int count = 1;
        bool isHappy = (m == 1);

        for (int x = 0; x < n - 1; x++)
        {
            if (grid[x][y] == grid[x + 1][y])
            {
                count++;

                if (count >= m)
                    isHappy = true;
            }
            else
            {
                count = 1;
            }
        }

        if (isHappy)
            happy++;
    }

    cout << happy << '\n';

    return 0;
}