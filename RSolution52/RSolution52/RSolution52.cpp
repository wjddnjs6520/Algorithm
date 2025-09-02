#include <iostream>
#include <string>
#include <vector>

using namespace std;


int solution(int a, int b, int n) {
    int answer = 0;
    while (n >= a) {
        int exchanged = (n / a) * b;
        answer += exchanged;
        n = exchanged + (n % a);
    }
    return answer;
}

int main()
{
    std::cout <<solution(2, 1, 20) << endl;
    std::cout << solution(3, 1, 20) << endl;
}

