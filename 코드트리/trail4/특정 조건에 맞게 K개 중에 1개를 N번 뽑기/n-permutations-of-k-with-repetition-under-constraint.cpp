#include <iostream>
#include <vector>
using namespace std;

void PrintAnswer(const vector<int>& answer)
{
    for (int value : answer)
    {
        cout << value << " ";
    }

    cout << "\n";
}

void Choose(int depth, int n, const vector<int>& arr, vector<int>& answer)
{
    if (depth == n)
    {
        PrintAnswer(answer);
        return;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (depth >= 2 &&
            arr[i] == answer[depth - 1] &&
            arr[i] == answer[depth - 2])
        {
            continue;
        }
        
        answer.push_back(arr[i]);
        Choose(depth + 1, n, arr, answer);
        answer.pop_back();
    }
}

int main()
{
    int k, n;
    cin >> k >> n;

    vector<int> arr;

    for (int i = 1; i <= k; i++)
        arr.push_back(i);

    vector<int> answer;
    Choose(0, n, arr, answer);

    return 0;
}