#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int age) {
    int answer = 0;
    answer = 2022 - age + 1;
    return answer;
}

int main()
{
    std::cout << solution(40)<<std::endl;
    std::cout << solution(23);
}


