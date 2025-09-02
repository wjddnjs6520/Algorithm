#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = - 1;
    long long ln = n;
    for (int i = 0; i < 500; i++) {
        if (ln % 2 == 0) {
            ln = ln / 2;
        }
        else {
            ln = ln * 3 + 1;
        }

        if (ln == 1) {
            answer = i + 1;
            break;
        }
    }

    return answer;
}


int main()
{
    std::cout << solution(6) << endl;
    std::cout << solution(16) << endl;
    std::cout << solution(626331) << endl;
}
