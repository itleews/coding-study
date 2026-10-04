#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;

    vector<vector<int>> belt(2, vector<int>(n));
    for (int i = 0; i < belt.size(); i++)
    {
        for (int j = 0; j < belt[i].size(); j++)
        {
            cin >> belt[i][j];
        }
    }

    for (int time = 0; time < t; time++)
    {
        int temp[2];

        int belt1End = belt[0].size() - 1;
        temp[0] = belt[0][belt1End];
        for (int i = belt1End; i >= 1; i--)
        {
            belt[0][i] = belt[0][i - 1];
        }

        int belt2End = belt[1].size() - 1;
        temp[1] = belt[1][belt2End];
        for (int i = belt2End; i >= 1; i--)
        {
            belt[1][i] = belt[1][i - 1];
        }

        belt[0][0] = temp[1];
        belt[1][0] = temp[0];
    }

    for (int i = 0; i < belt.size(); i++)
    {
        for (int j = 0; j < belt[i].size(); j++)
        {
            cout << belt[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}