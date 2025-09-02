#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int temp = 0;
    int n = x;
    while (n > 10) {
        temp += n % 10;
        n = n / 10;
    }
    temp += n;

    if (x % temp != 0) {
        answer = false;
    }

    return answer;
}

int main()
{
    std::cout << solution(12)<<endl;
    std::cout << solution(12) << endl;
    std::cout << solution(11) << endl;
    std::cout << solution(13) << endl;
}