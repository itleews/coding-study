#include <iostream>
#include <string>
using namespace std;

int main()
{
    int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    string day[7] = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };

    int m1, d1, m2, d2;
    cin >> m1 >> d1 >> m2 >> d2;

    int start = 0;
    for (int i = 1; i < m1; i++)
    {
        start += days[i];
    }
    start += d1;

    int end = 0;
    for (int i = 1; i < m2; i++)
    {
        end += days[i];
    }
    end += d2;

    int elapsed = end - start;
    if (elapsed < 0)
    {
        elapsed += 364;
    }

    cout << day[elapsed % 7] << "\n";

    return 0;
}