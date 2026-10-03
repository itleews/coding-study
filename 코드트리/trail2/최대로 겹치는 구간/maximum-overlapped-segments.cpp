#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> count(201, 0);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        for (int j = a; j < b; j++)
            count[j + 100]++;
    }

    int answer = 0;

    for (int x : count)
        answer = max(answer, x);

    cout << answer;
    return 0;
}