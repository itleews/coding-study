#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string binary;
    cin >> binary;

    int decimal = 0;
    for (char c : binary)
    {
        decimal = decimal * 2 + (c - '0');
    }

    decimal *= 17;

    vector<int> result;

    while (decimal >= 2)
    {
        result.push_back(decimal % 2);
        decimal /= 2;
    }
    result.push_back(decimal);

    while (!result.empty())
    {
        cout << result.back();
        result.pop_back();
    }

    return 0;
}