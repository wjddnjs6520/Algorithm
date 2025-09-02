#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer;
    int num = 0;
    int xnum = x;
    while (xnum > 10) {
        num += xnum % 10;
        xnum = xnum / 10;
    }
    num += xnum;
    if (x % num == 0) {
        answer = true;
    }
    else {
        answer = false;
    }

    return answer;
}

int main()
{
    std::cout << solution(12) << endl;
    std::cout << solution(12) << endl;
    std::cout << solution(11) << endl;
    std::cout << solution(13) << endl;
}