#include <iostream>
#include <string>
using namespace std;

int main()
{
    string binary;
    cin >> binary;

    int result = 0;

    for (char c : binary)
    {
        result = result * 2 + (c - '0');
    }

    cout << result << '\n';

    return 0;
}