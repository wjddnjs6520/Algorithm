#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num1, int num2) {
    int answer = 0;
    answer = num1 * num2;
    return answer;
}

int main()
{
    std::cout << solution(3, 4) << std::endl;
    std::cout << solution(27, 19);

    return 0;
}
