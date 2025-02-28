#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int score = 0, num = 0;
        char str[81];
        cin >> str;
        size_t length = strlen(str);
        for (int j = 0; j < length; j++) {
            if (str[j] == 'O') {
                num++;
                score += num;
            }
            else {
                num = 0;
            }
        }
        cout << score << endl;
    }
}