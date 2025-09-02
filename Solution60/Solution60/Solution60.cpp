#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;

    for (int i = 1; i <= number; i++) {
        int temp = 0;
        for (int j = 1; j <= sqrt(i); j++) {
            if (i % j == 0) {
                temp += 2;  // j와 i/j 두 개
                if (j * j == i) temp--;  // 제곱수면 중복 제거
            }
        }

        if (temp > limit) {
            answer += power;
        }
        else {
            answer += temp;
        }
    }

    return answer;
}

int main()
{
    cout << solution(5, 3, 2) << endl;
    cout << solution(10, 3, 2) << endl;
}

