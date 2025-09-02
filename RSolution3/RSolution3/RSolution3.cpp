#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

using namespace std;

int solution(int num1, int num2) {
    int answer = 0;
    answer = num1 / num2;
    return answer;
}

int main()
{
    cout << solution(10, 5) << endl;
    cout << solution(7, 2);
    return 0;
}