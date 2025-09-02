#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    if (s[0] == '-') {
        answer = stoi(s.substr(1, s.length() - 1));
        answer *= -1;
    }
    else {
        answer = stoi(s.substr(0, s.length()));;
    }

    return answer;
}

int main()
{
    std::cout << solution("1234") << endl;
    std::cout << solution("-1234") << endl;
}
