#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> block(n);
    for (int i = 0; i < n; i++)
    {
        cin >> block[i];
    }

    int time = 2;
    while (time)
    {
        int start, end;
        cin >> start >> end;

        block.erase(block.begin() + (start - 1), block.begin() + end);

        time--;
    }

    cout << block.size() << "\n";
    for (auto& b : block)
    {
        cout << b << "\n";
    }

    return 0;
}