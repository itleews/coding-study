#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a;

    while (n--)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "push_back")
        {
            int x;
            cin >> x;
            a.push_back(x);
        }
        else if (cmd == "pop_back")
        {
            a.pop_back();
        }
        else if (cmd == "size")
        {
            cout << a.size() << '\n';
        }
        else if (cmd == "get")
        {
            int k;
            cin >> k;
            cout << a[k - 1] << '\n';
        }
    }
    return 0;
}