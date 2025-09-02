#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int solution(int num1, int num2) {
    int answer = 0;
    answer = num1 - num2;
    return answer;
}

int main() {

    cout << solution(2, 3) << endl;
    cout << solution(100, 2);

    return 0;
}