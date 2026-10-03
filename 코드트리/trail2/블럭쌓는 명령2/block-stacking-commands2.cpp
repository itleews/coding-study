#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> block(n, 0);

    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        for (int j = a; j <= b; j++)
        {
            block[j - 1]++;
        }
    }

    int result = 0;
    for (int i = 0; i < block.size(); i++)
    {
        result = max(result, block[i]);
    }

    cout << result;

    return 0;
}