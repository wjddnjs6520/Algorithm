#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long start = 1;
    long long end = n;
    long long p_start = 0;
    long long p_end = 0;
    long long x = (long long)(start + end) / 2;
    while (true) {
        if (n / x == x) {
            if (x * x == n) {
                answer = (x + 1) * (x + 1);
                break;
            }
        }
        if ((long long)n / x > x) {
            p_start = start;
            p_end = end;
            start = x;
            x = (long long)(start + end) / 2;
        }
        else {
            p_start = start;
            p_end = end;
            end = x;
            x = (long long)(start + end) / 2;
        }
        if (p_end == end && p_start == start) {
            answer = -1;
            break;
        }
    }
    return answer;
}

int main()
{
    cout << solution(121)<<endl;
    cout << solution(3) << endl;    
}
