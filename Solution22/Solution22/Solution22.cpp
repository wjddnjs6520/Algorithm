#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    if (a > b) {
        int temp = b;
        b = a;
        a = temp;
    }

    for (int i = a; i <= b; i++) {
        answer += i;
    }

    return answer;
}
int main()
{
    std::cout << solution(3, 5) << endl;
    std::cout << solution(3, 3) << endl;
    std::cout << solution(5, 3) << endl;
}
