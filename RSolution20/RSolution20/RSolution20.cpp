#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> s;

    while (n > 10) {
        s.push_back(n % 10);
        n = n / 10;
    }
    s.push_back(n);

    sort(s.begin(), s.end(), greater<int>());

    for (int i = 0; i < s.size(); i++) {
        answer += s[i];
        if (i < s.size() - 1) {
            answer *= 10;
        }
    }

    return answer;
}

int main()
{
    std::cout << solution(118372);
}
