#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            cin >> grid[i][j];
        }
    }

    int maxArea = -1;
    for (int x1 = 0; x1 < n; x1++)
    {
        for (int y1 = 0; y1 < m; y1++)
        {
            for (int x2 = x1; x2 < n; x2++)
            {
                for (int y2 = y1; y2 < m; y2++)
                {
                    bool positive = true;

                    for (int x = x1; x <= x2; x++)
                    {
                        for (int y = y1; y <= y2; y++)
                        {
                            if (grid[x][y] <= 0)
                            {
                                positive = false;
                                break;
                            }
                        }
                    }

                    if (positive)
                    {
                        int width = x2 - x1 + 1;
                        int height = y2 - y1 + 1;
                        int area = width * height;
                        maxArea = max(area, maxArea);
                    }
                }
            }
        }
    }
    
    cout << maxArea;
    return 0;
}