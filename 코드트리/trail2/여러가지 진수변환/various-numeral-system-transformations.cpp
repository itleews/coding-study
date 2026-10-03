#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, b;
    cin >> n >> b;

    vector<int> bin;
    while (n >= b)
    {
        bin.push_back(n % b);
        n /= b;
    }
    bin.push_back(n);

    while (!bin.empty())
    {
        cout << bin.back();
        bin.pop_back();
    }

    return 0;
}