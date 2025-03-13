#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;  // N 입력받기

    int count = 0;  // 종말의 수 개수
    int num = 666;  // 666부터 시작

    while (true) {
        if (to_string(num).find("666") != string::npos) { // "666" 포함 여부 확인
            count++;
        }
        if (count == N) {  // N번째 종말의 수 찾으면 출력 후 종료
            cout << num << endl;
            break;
        }
        num++;  // 숫자 증가
    }

    return 0;
}
