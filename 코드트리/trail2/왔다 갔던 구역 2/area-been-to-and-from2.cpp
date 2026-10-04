#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> block(2200, 0);

    int currentPos = 1100;
    for (int i = 0; i < n; i++)
    {
        int x;
        string direction;

        cin >> x >> direction;

        if (direction == "R")
        {
            int goalPos = currentPos + x;
            for (int j = currentPos; j < goalPos; j++)
            {
                block[j]++;
            }
            currentPos = goalPos;
        }
        else
        {
            int goalPos = currentPos - x;
            for (int j = currentPos; j > goalPos; j--)
            {
                block[j - 1]++;
            }
            currentPos = goalPos;
        }

    }

    int result = 0;
    for (int i = 0; i < block.size(); i++)
    {
        if (block[i] >= 2)
            result++;
    }

    cout << result;
    return 0;
}