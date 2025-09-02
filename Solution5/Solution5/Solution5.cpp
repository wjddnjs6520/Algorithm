#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num1, int num2) {
    int answer = 0;
    if (num1 == num2) {
        answer = 1;
    }
    else {
        answer = -1;
    }
    return answer;
}

int main()
{
    std::cout << solution(2, 3)<<std::endl;
    std::cout << solution(11, 11)<<std::endl;
    std::cout << solution(7, 99);
    return 0;
}
