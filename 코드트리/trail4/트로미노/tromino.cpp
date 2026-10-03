#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    int answer = 0;

    // ㄴ
    for (int x = 0; x < n - 1; x++)
    {
        for (int y = 0; y < m - 1; y++)
        {
            int sum;

            // A A
            // A
            sum = grid[x][y]
                + grid[x + 1][y]
                + grid[x][y + 1];

            answer = max(answer, sum);

            // A A
            //   A
            sum = grid[x][y]
                + grid[x][y + 1]
                + grid[x + 1][y + 1];

            answer = max(answer, sum);

            // A
            // A A
            sum = grid[x][y]
                + grid[x + 1][y]
                + grid[x + 1][y + 1];

            answer = max(answer, sum);

            //   A
            // A A
            sum = grid[x][y + 1]
                + grid[x + 1][y]
                + grid[x + 1][y + 1];

            answer = max(answer, sum);
        }
    }

    // 세로 ㅡ
    for (int x = 0; x < n - 2; x++)
    {
        for (int y = 0; y < m; y++)
        {
            int sum = grid[x][y]
                     + grid[x + 1][y]
                     + grid[x + 2][y];

            answer = max(answer, sum);
        }
    }

    // 가로 ㅡ
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m - 2; y++)
        {
            int sum = grid[x][y]
                     + grid[x][y + 1]
                     + grid[x][y + 2];

            answer = max(answer, sum);
        }
    }

    cout << answer << '\n';

    return 0;
}