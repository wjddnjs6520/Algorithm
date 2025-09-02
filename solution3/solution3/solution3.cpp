#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num1, int num2) {
    int answer = 0;
    answer = num1 / num2;
    return answer;
}

int main()
{
    std::cout << solution(10, 5)<<std::endl;
    std::cout << solution(7, 2);
    return 0;
}
