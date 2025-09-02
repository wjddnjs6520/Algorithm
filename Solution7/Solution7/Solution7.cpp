#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num1, int num2) {
    int answer = 0;
    answer = (float)num1 / num2 * 1000;
    return answer;
}

int main()
{
    std::cout << solution(3, 2)<<std::endl;
    std::cout << solution(7, 3)<<std::endl;
    std::cout << solution(1, 16);
}
