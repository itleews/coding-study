#include <iostream>
using namespace std;

int main()
{
    int m1, m2, d1, d2;
    cin >> m1 >> d1 >> m2 >> d2;

    int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int start = 0;
    int end = 0;

    for (int i = 1; i < m1; i++)
    {
        start += days[i];
    }
    start += d1;

    for (int i = 1; i < m2; i++)
    {
        end += days[i];
    }
    end += d2;

    cout << end - start + 1 << "\n";
    return 0;
}