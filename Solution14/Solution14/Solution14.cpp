#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            answer += i;
        }
    }
    return answer;
}

int main()
{
    int a = 12;
    int b = 5;
    std::cout << solution(a) << endl;
    std::cout << solution(b) << endl;
}

