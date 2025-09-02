#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

using namespace std;

int solution(int num1, int num2) {
    int answer = -1;
    if (num1 == num2) {
        answer = 1;
    }

    return answer;
}

int main()
{
    cout << solution(2, 3) << endl;
    cout << solution(11, 11) << endl;
    cout << solution(7, 99);
    return 0;
}