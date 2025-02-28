#include <iostream>
#include <string>
using namespace std;

// 퀵 정렬을 위한 문자열 비교 함수
bool compare(const string& a, const string& b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();  // 길이 짧은 순
    }
    return a < b;  // 길이가 같다면 사전순
}

// 퀵 정렬 구현
void quickSort(string* arr, int left, int right) {
    if (left >= right) return;
    
    string pivot = arr[(left + right) / 2];  // 중앙값을 피벗으로 설정
    int i = left, j = right;
    
    while (i <= j) {
        while (compare(arr[i], pivot)) i++;  // 피벗보다 작은 값 찾기
        while (compare(pivot, arr[j])) j--;  // 피벗보다 큰 값 찾기
        
        if (i <= j) {  // Swap
            string temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++; j--;
        }
    }

    quickSort(arr, left, j);  // 왼쪽 부분 정렬
    quickSort(arr, i, right); // 오른쪽 부분 정렬
}

int main() {
    int N;
    cin >> N;
    string* words = new string[N];  // 동적 할당

    int size = 0;
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;

        // 중복 확인 및 제거
        bool isDuplicate = false;
        for (int j = 0; j < size; j++) {
            if (words[j] == word) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            words[size++] = word;  // 중복이 없을 때만 추가
        }
    }

    // 정렬 수행 (퀵 정렬)
    quickSort(words, 0, size - 1);

    // 정렬된 단어 출력
    for (int i = 0; i < size; i++) {
        cout << words[i] << endl;
    }

    delete[] words;  // 동적 할당 해제
    return 0;
}
