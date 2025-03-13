#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

int Mean (int arr[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return round(sum / n);
}

int Median (int arr[], int n) {
    sort(arr, arr + n);
    return arr[n / 2];
}

int Mode (int arr[], int n) {
    map<int, int> freq;
    
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
    
    int maxFreq = 0;
    vector<int> modes;
    
    for (auto it : freq) {
        if (it.second > maxFreq) {
            maxFreq = it.second;
            modes = {it.first};
        }
        else if (it.second == maxFreq) {
            modes.push_back(it.first);
        }
    }
    
    if (modes.size() > 1) {
        sort(modes.begin(), modes.end());
        return modes[1];
    }

    return modes[0];
}

int Range(int arr[], int n) {
    sort(arr, arr + n);
    return arr[n - 1] - arr[0];
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    cout << Mean(&arr[0], N) << '\n';
    cout << Median(&arr[0], N) << '\n';
    cout << Mode(&arr[0], N) << '\n';
    cout << Range(&arr[0], N) << '\n';
    return 0;
}