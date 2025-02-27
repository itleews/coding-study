#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    while (N--) {
        string str;
        cin >> str;

        int balance = 0;
        bool isValid = true;

        for (char ch : str) {
            if (ch == '(') balance++;
            else {
                balance--;
                if (balance < 0) {
                    isValid = false;
                    break;
                }
            }
        }

        cout << (isValid && balance == 0 ? "YES" : "NO") << '\n';
    }

    return 0;
}