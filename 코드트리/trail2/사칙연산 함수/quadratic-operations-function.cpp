#include <iostream>
using namespace std;

int main()
{
    int a, b;
    char o;

    cin >> a >> o >> b;

    if (o == '+')
    {
        cout << a << " + " << b << " = " << a + b << '\n';
        return 0;
    }

    if (o == '-')
    {
        cout << a << " - " << b << " = " << a - b << '\n';
        return 0;
    }

    if (o == '*')
    {
        cout << a << " * " << b << " = " << a * b << '\n';
        return 0;
    }

    if (o == '/')
    {
        cout << a << " / " << b << " = " << a / b << '\n';
        return 0;
    }

    cout << "False" << '\n';
    return 0;
}