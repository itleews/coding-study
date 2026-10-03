#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int start = a * 60 + b;
    int end = c * 60 + d;

    int result = end - start;

    if (result < 0)
    {
        result += 24 * 60;
    }
    
    cout << result << '\n';
    return 0;
}