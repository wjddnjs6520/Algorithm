#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long temp = sqrt(n);
    if (temp * temp == n) {
        answer = (temp + 1) * (temp + 1);
    }
    else {
        answer = -1;
    }
    return answer;
}

int main()
{
    std::cout << solution(121) << endl;
    std::cout << solution(3) << endl;
}

