#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    string n;
    cin >> n;

    int decimal = 0;
    for (char c : n)
    {
        decimal = decimal * a + (c - '0');
    }

    vector<int> result;
    while (decimal >= b)
    {
        result.push_back(decimal % b);
        decimal /= b;
    }
    result.push_back(decimal);

    while (!result.empty())
    {
        cout << result.back();
        result.pop_back();
    }

    return 0;
}