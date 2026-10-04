#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;

    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int item;
        cin >> item;
        arr.push_back(item);
    }

    int len = 0, result = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > t)
        {
            len++;
        }
        else
        {
            len = 0;
        }

        result = max(len, result);
    }

    cout << result;
    return 0;
}