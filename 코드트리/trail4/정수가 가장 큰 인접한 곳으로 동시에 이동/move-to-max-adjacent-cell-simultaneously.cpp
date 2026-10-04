#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m, t;
    cin >> n >> m >> t;

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

    vector<int> row(m);
    vector<int> col(m);
    for (int i = 0; i < m; i++)
    {
        cin >> row[i] >> col[i];
        --row[i]; --col[i];
    }

    for (int time = 0; time < t; time++)
    {
        for (int i = 0; i < row.size(); i++)
        {
            int maxValue = -1;
            int maxRow = row[i];
            int maxCol = col[i];

            for (int j = 0; j < 4; j++)
            {
                int nr = row[i] + dx[j];
                int nc = col[i] + dy[j];

                if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                    continue;

                if (grid[nr][nc] > maxValue)
                {
                    maxValue = grid[nr][nc];
                    maxRow = nr;
                    maxCol = nc;
                }
            }

            row[i] = maxRow;
            col[i] = maxCol;
        }

        vector<int> nextRow;
        vector<int> nextCol;

        for (int i = 0; i < row.size(); i++)
        {
            bool collision = false;

            for (int j = 0; j < row.size(); j++)
            {
                if (i != j &&
                    row[i] == row[j] &&
                    col[i] == col[j])
                {
                    collision = true;
                    break;
                }
            }

            if (!collision)
            {
                nextRow.push_back(row[i]);
                nextCol.push_back(col[i]);
            }
        }

        row = nextRow;
        col = nextCol;
    }

    cout << row.size();
    return 0;
}