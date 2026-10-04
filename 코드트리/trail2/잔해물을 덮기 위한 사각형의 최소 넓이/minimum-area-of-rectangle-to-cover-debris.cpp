#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<bool>> grid(2000, vector<bool>(2000, false));
    int offset = 1000;

    for (int i = 0; i < 2; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        x1 += offset;
        y1 += offset;
        x2 += offset;
        y2 += offset;

        for (int x = x1; x < x2; x++)
        {
            for (int y = y1; y < y2; y++)
            {
                if (i == 0)
                {
                    grid[x][y] = true;
                }
                else
                {
                    grid[x][y] = false;
                }
            }
        }
    }

    int maxX = 0, minX = 2000;
    int maxY = 0, minY = 2000;
    bool hasDebris = false;

    for (int x = 0; x < grid.size(); x++)
    {
        for (int y = 0; y < grid[x].size(); y++)
        {
            if (grid[x][y])
            {
                hasDebris = true;
                maxX = max(maxX, x);
                minX = min(minX, x);
                maxY = max(maxY, y);
                minY = min(minY, y);
            }
        }
    }

    if (!hasDebris)
    {
        cout << 0;
    }
    else
    {
        int dx = maxX - minX + 1;
        int dy = maxY - minY + 1;
        cout << dx * dy;
    }
    return 0;
}