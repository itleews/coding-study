#include <iostream>
#include <string>
using namespace std;

bool isNum(const string& s) {
    if (s != "Fizz" && s != "Buzz" && s != "FizzBuzz") {
        return true;
    }
    else {
        return false;
    }
}

string getFizzBuzz(int num) {
    if (num % 3 == 0 && num % 5 == 0) {
        return "FizzBuzz";
    } else if (num % 3 == 0) {
        return "Fizz";
    } else if (num % 5 == 0) {
        return "Buzz";
    } else {
        return to_string(num);
    }
}

int main() {
    string str1, str2, str3;
    int nextNum;
    cin >> str1;
    cin >> str2;
    cin >> str3;
    
    if (isNum(str1)) {
        nextNum = stoi(str1) + 3;
    } else if (isNum(str2)) {
        nextNum = stoi(str2) + 2;
    } else if (isNum(str3)) {
        nextNum = stoi(str3) + 1;
    } else {
        nextNum = 15;
    }
    
    cout << getFizzBuzz(nextNum) << endl;
    
    return 0;
}