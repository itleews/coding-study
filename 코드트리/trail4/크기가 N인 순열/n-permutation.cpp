#include <iostream>
#include <vector>
using namespace std;

void PrintAnswer(const vector<int>& answer)
{
    for (int value : answer)
        cout << value << " ";

    cout << "\n";
}

void Choose(int depth, int n, const vector<int>& arr, vector<int>& answer, vector<bool>& visited)
{
    if (depth == n)
    {
        PrintAnswer(answer);
        return;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (visited[arr[i]])
            continue;

        visited[arr[i]] = true;

        answer.push_back(arr[i]);
        Choose(depth + 1, n, arr, answer, visited);
        answer.pop_back();

        visited[arr[i]] = false;
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;

    vector<int> answer;
    vector<bool> visited(n + 1, false);

    Choose(0, n, arr, answer, visited);

    return 0;
}