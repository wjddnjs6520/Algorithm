#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<long long> fibov(2001, -1);

long long fibo(int n1) {
    if (fibov[1] == -1) {
        fibov[1] = 1;
        fibov[2] = 2;
    }
    if (fibov[n1] == -1) {
        fibov[n1] = (fibo(n1 - 1) % 1234567 + fibo(n1 - 2) % 1234567) % 1234567;

    }

    return fibov[n1];

}


long long solution(int n) {
    long long answer = 0;
    answer = fibo(n) % 1234567;
    return answer;
}

int main()
{
    std::cout << solution(4) <<endl;
    std::cout << solution(3) << endl;
}

