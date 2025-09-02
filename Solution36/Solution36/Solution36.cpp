#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    if (s.size() == 4 || s.size() == 6) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] > 47 && s[i] < 58) {

            }
            else {
                answer = false;
            }
        }
    }
    else {
        answer = false;
    }
    return answer;
}

int main() {
    cout << solution("a234")<< endl;
    cout << solution("1234") << endl;
}
