#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    int n = 0;
    long long num1 = num;
    while (num1 > 1) {
        n++;
        if (num1 % 2 == 0) {
            num1 = num1 / 2;
        }
        else {
            num1 = num1 * 3 + 1;
        }

        if (n >= 500) {
            answer = -1;
            break;
        }
    }
    if (num == 1) {
        answer = 0;
    }
    if (num1 == 1) {
        answer = n;
    }
    return answer;
}

int main()
{
    std::cout << solution(6) << endl;
    std::cout << solution(16) << endl;
    std::cout << solution(626331)<<endl;
}