#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    string answer = "";
    
    for (int i = 0; i < overwrite_string.size(); i++) {
        my_string[s] = overwrite_string[i];
        s++;
    }
    
    answer = my_string;
    return answer;
}