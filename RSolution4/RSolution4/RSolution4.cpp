#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

using namespace std;


int solution(int age) {
    int answer = 0;
    answer = 2022 - age + 1;
    return answer;
}

int main()
{
    cout << solution(40) << endl;
    cout << solution(23);
}