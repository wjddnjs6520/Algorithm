#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = 0;

    bool sbool = true;

    for (int i = 0; i < s.size(); i++) {
        stack<char> sstack;
        for (char c : s) {
            if (c == '[' || c == '{' || c == '(') {
                sstack.push(c);
            }
            else {
                if (sstack.empty()) {
                    sbool = false;
                    break;
                }
                char back = sstack.top();
                if (c == ']' && back == '[' ||
                    c == '}' && back == '{' ||
                    c == ')' && back == '(') {
                    sstack.pop();
                }
                else {
                    sbool = false;
                    break;
                }
            }
        }
        if (sbool && sstack.empty()) {
            answer++;
        }
        sbool = true;
        char first_char = s[0];
        s.erase(s.begin());
        s.push_back(first_char);
    }

    return answer;
}

int main()
{
    cout << solution("[](){}") << endl;
    cout << solution("}]()[{") << endl;
    cout << solution("[)(]") << endl;
    cout << solution("}}}") << endl;
}

