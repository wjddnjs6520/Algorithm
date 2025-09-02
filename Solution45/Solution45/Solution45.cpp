#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            answer += s[i];
        }
        else if (s[i] <= 'Z') {
            answer += 'A' + (s[i] - 'A' + n) % 26;
        }
        else if (s[i] <= 'z') {
            answer += 'a' + (s[i] - 'a' + n) % 26;
        }
    }
    return answer;
}


int main()
{
    string s1 = "AB";
    string s2 = "z";
    string s3 = "a B z";

    cout << solution(s1, 1) << endl;
    cout << solution(s2, 1) << endl;
    cout << solution(s3, 4) << endl;

}

