#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int angle) {
    int answer = 0;
    if (angle > 0 && angle < 90) {
        answer = 1;
    }
    else if (angle == 90) {
        answer = 2;
    }
    else if (angle < 180) {
        answer = 3;
    }
    else{
        answer = 4;
    }

    return answer;
}

int main()
{
    std::cout << solution(70) << std::endl;
    std::cout << solution(91) << std::endl;
    std::cout << solution(180);
}
