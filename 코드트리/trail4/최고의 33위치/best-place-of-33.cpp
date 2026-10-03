#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));

    for (int idx = 0; idx < n; idx++)
    {
        for (int jdx = 0; jdx < n; jdx++)
        {
            cin >> a[idx][jdx];
        }
    }

    int answer = 0;

    for (int idx = 0; idx <= n - 3; idx++)
    {
        for (int jdx = 0; jdx <= n - 3; jdx++)
        {
            int count = 0;
            for (int x = idx; x < idx + 3; x++)
            {
                for (int y = jdx; y < jdx + 3; y++)
                {
                    count += a[x][y];
                }
            }
            answer = max(answer, count);
        }
    }

    cout << answer << '\n';

    return 0;
}