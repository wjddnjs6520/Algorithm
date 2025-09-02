#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for (int x = 2; x < n; x++) {
        if (n % x == 1) {
            answer = x;
            break;
        }
    }
    return answer;
}

int main()
{
    int a = 10;
    int b = 12;
    std::cout << solution(a) << endl;
    std::cout << solution(b) << endl;
}
