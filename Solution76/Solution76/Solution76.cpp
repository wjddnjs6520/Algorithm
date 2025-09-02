#include <string>
#include <vector>
#include <cctype>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    bool isstart = true;
    for (char c : s) {
        //첫글자고 알파뱃이면
        if (isstart && isalpha(c)) {
            answer += toupper(c);
            isstart = false;
        }
        //첫글자 아니고 알파뱃이면
        else if (!isstart && isalpha(c)) {
            answer += tolower(c);
        }
        //숫자 혹은 공백
        else {
            answer += c;
            if (c == ' ') {
                isstart = true;
            }
            else {
                isstart = false;
            }
        }
    }
    return answer;
}


int main() {

    cout << solution("3people unFollowed me") << endl;
    cout << solution("for the last week") << endl;
    return 0;
}