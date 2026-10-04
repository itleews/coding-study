#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<bool>> grid(2000, vector<bool>(2000, false));
    int offset = 1000;

    for (int i = 0; i < 3; i++)
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
                if (i != 2)
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

    auto result = 0;
    for (int x = 0; x < grid.size(); x++)
    {
        for (int y = 0; y < grid[x].size(); y++)
        {
            if (grid[x][y])
            {
                result += 1;
            }
        }
    }

    cout << result;
    return 0;
}