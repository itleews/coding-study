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

    int answer = 0;

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            for (int k = 0; k <= n; k++)
            {
                int gold = 0;

                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (abs(i - r) + abs(j - c) <= k)
                        {
                            gold += grid[i][j];
                        }
                    }
                }

                int cost = k * k + (k + 1) * (k + 1);
                int revenue = gold * m;
                
                if (revenue >= cost)
                {
                    answer = max(answer, gold);
                }
            }
        }
    }

    cout << answer << '\n';
    return 0;
}