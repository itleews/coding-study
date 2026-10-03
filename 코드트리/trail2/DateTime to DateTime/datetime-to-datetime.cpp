#include <iostream>
using namespace std;

int main()
{
    int day, hour, min;
    cin >> day >> hour >> min;

    int start = 11 * 1440 + 11 * 60 + 11;
    int end = day * 1440 + hour * 60 + min;

    int elapsed = end - start;
    int answer = elapsed >= 0 ? elapsed : -1;
    cout << answer << "\n";
    return 0;
}