#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;

    for (int i = left; i <= right; i++) {
        int x = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                x++;
            }
        }
        if (x % 2 == 0) {
            answer += i;
        }
        else {
            answer -= i;
        }
    }
    return answer;
}

int main()
{
    std::cout << solution(13, 17)<<endl;
    std::cout << solution(24, 27) << endl;
}