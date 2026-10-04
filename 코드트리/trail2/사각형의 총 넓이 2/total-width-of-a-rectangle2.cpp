#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> grid(200, vector<int>(200));
    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        x1 += 100;
        y1 += 100;
        x2 += 100;
        y2 += 100;

        for (int x = x1; x < x2; x++)
        {
            for (int y = y1; y < y2; y++)
            {
                grid[x][y] = 1;
            }
        }
    }

    auto result = 0;
    for (int x = 0; x < grid.size(); x++)
    {
        for (int y = 0; y < grid.size(); y++)
        {
            if (grid[x][y] == 1)
            {
                result += 1;
            }
        }
    }

    cout << result;
    return 0;
}