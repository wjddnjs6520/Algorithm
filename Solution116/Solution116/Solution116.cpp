#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    long long longd = d;
    for (long long i = 0; i <= d; i += k) {
        long long y_max = sqrt(longd * longd - i * i);
        answer += y_max / k + 1;
    }
    return answer;
}

int main() {
    cout << solution(2, 4) << endl;
    cout << solution(1, 5) << endl;
    return 0;
}
