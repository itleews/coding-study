#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<pair<int, string>> members(N); // (나이, 이름) 저장

    for (int i = 0; i < N; i++) {
        cin >> members[i].first >> members[i].second; // 나이, 이름 입력
    }

    // Stable Sort 사용 (나이 기준)
    stable_sort(members.begin(), members.end(), [](const pair<int, string> &a, const pair<int, string> &b) {
        return a.first < b.first; // 나이 오름차순 정렬
    });

    // 결과 출력
    for (const auto &member : members) {
        cout << member.first << " " << member.second << '\n';
    }

    return 0;
}
