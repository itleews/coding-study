#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, r, c;
    cin >> n >> r >> c;
    r--; c--;

    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };

    std::vector<int> root;
    root.push_back(grid[r][c]);

    while (true)
    {
        int current = grid[r][c];
        bool moved = false;

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                continue;

            if (current < grid[nr][nc])
            {
                r = nr;
                c = nc;

                root.push_back(grid[r][c]);
                moved = true;
                break;
            }
        }

        if (!moved)
            break;
    }

    for (int i = 0; i < root.size(); i++)
    {
        cout << root[i] << " ";
    }

    return 0;
}