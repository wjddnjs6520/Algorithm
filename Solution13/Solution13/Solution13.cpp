#include <iostream>
using namespace std;

int solution(int n)
{
    int answer = 0;

    while (true) {
        int temp = n % 10;
        n = n / 10;
        answer += temp;
        if (n < 10) {
            answer += n;
            break;
        }
    }
    return answer;
}

int main()
{
    int a = 123;
    int b = 987;
    std::cout << solution(a)<<endl;
    std::cout << solution(b) << endl;
}


