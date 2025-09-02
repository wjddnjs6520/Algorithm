#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;

    if (s[0] == '-') {
        answer = -1 * stoi(s.substr(1, s.size()));
    }
    else {
        answer = stoi(s.substr(0, s.size()));
    }

    return answer;
}

int main()
{
    std::cout << solution("1234") << endl;
    std::cout << solution("-1234") << endl;
    std::cout << solution("88861") << endl;
    std::cout << solution("-111111") << endl;
}

