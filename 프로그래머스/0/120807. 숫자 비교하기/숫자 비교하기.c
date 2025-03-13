#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num1, int num2) {
    int answer;
    if (num1 == num2)
        answer = 1;
    else
        answer = -1;
    return answer;
}