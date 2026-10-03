#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int min = 0;

    while (a != c || b != d)
    {
        b++;

        if (b == 60)
        {
            a++;
            b = 0;

            if (a == 24)
                a = 0;
        }

        min++;
    }
    cout << min << '\n';
    return 0;
}