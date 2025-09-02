#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";

    for (char c : s) {
        if (c == ' ') {
            answer += c;
        }
        else if (c >= 'A' && c <= 'Z') {
            answer += (c + n - 'A') % 26 + 'A';
        }
        else if (c >= 'a' && c <= 'z') {
            answer += (c + n - 'a') % 26 + 'a';
        }
    }

    return answer;
}

int main()
{
    cout << solution("AB", 1) << endl;
    cout << solution("z", 1) << endl;
    cout << solution("a B z", 4) << endl;
}

