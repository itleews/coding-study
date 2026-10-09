#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
const int MAX_VAL = 1000000;

void Calc()
{
    queue<int> q;
    vector<int> dist(MAX_VAL + 1, -1);

    q.push(n);
    dist[n] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cur == 1)
        {
            cout << dist[1];
            return;
        }

        vector<int> nextVal;
        nextVal.push_back(cur - 1);
        nextVal.push_back(cur + 1);
        if (cur % 2 == 0)
            nextVal.push_back(cur / 2);
        if (cur % 3 == 0)
            nextVal.push_back(cur / 3);


        for (int next : nextVal)
        {
            if (next < 1 || next > MAX_VAL)
                continue;

            if (dist[next] != -1)
                continue;

            dist[next] = dist[cur] + 1;
            q.push(next);
        }

    }
}

int main()
{
    cin >> n;
    Calc();
    return 0;
}