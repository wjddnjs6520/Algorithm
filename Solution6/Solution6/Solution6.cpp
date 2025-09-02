#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num1, int num2) {
    int answer = -1;
    answer = num1 + num2;
    return answer;
}

int main()
{
    std::cout << solution(2, 3)<<std::endl;
    std::cout << solution(100, 2);
}
