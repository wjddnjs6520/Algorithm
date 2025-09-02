#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    for (int i = 1; i < n + 1; i++) {
        if (i % 2 == 0) {
            answer += i;
        }
    }
    return answer;
}

int main()
{
    std::cout << solution(10)<<std::endl;
    std::cout << solution(4);
}
