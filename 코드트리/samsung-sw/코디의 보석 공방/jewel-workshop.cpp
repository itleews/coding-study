#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Jewel
{
    int weight;
    int value;
    bool isExist = true;
};

vector<Jewel> jewels;

void Ready()
{
    int w, v;
    cin >> w >> v;
    jewels.push_back({ w, v });
}

void Receive()
{
    int w, v;
    cin >> w >> v;
    jewels.push_back({ w, v });
}

void Sell()
{
    int idx;
    cin >> idx;

    if (idx > 0 && idx < jewels.size() && jewels[idx].isExist)
    {
        cout << jewels[idx].value << "\n";
        jewels[idx].isExist = false;
    }
    else
    {
        cout << -1 << "\n";
    }
}

void Display()
{
    int maxWeight;
    cin >> maxWeight;

    vector<long long> dp(maxWeight + 1, 0);

    for (int i = 1; i < jewels.size(); i++)
    {
        if (!jewels[i].isExist)
            continue;

        int weight = jewels[i].weight;
        int value = jewels[i].value;

        for (int c = maxWeight; c >= weight; c--)
        {
            dp[c] = max(dp[c], dp[c - weight] + value);
        }
    }

    cout << dp[maxWeight] << '\n';
}

void Set()
{
    int maxDiff;
    cin >> maxDiff;

    vector<int> validWeights;
    for (auto j : jewels)
    {
        if (j.isExist)
            validWeights.push_back(j.weight);
    }

    if (validWeights.size() < 2)
    {
        cout << 0 << "\n";
        return;
    }

    long long setCount = 0;

    sort(validWeights.begin(), validWeights.end());

    int right = 0;
    for (int left = 0; left < validWeights.size(); left++)
    {
        while (right < validWeights.size() && validWeights[right] - validWeights[left] <= maxDiff)
        {
            right++;
        }
        setCount += (right - left - 1);
    }

    cout << setCount << "\n";
}


int main()
{
    int q;
    cin >> q;

    jewels.push_back({ 0, 0, false });

    while (q--)
    {
        int work;
        cin >> work;

        switch (work)
        {
        case 1:
        {
            int n;
            cin >> n;

            for (int i = 0; i < n; i++)
            {
                Ready();
            }
            break;
        }
        case 2:
            Receive();
            break;
        case 3:
        {
            Sell();
            break;
        }
        case 4:
            Display();
            break;
        case 5:
            Set();
            break;
        default:
            break;
        }
    }

    return 0;
}