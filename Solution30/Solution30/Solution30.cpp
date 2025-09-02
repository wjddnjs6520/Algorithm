#include <iostream>
#include <string>
#include <vector>

using namespace std;
string solution(string s) {
    string answer = "";
    if (s.size() % 2 != 0) {
        answer = s[s.size() / 2];
    }
    else {
        answer = s[s.size() / 2 - 1];
        answer += s[s.size() / 2];
    }
    return answer;
}

int main()
{
	string s1 = "abcde";
    string s2 = "qwer";
	cout << solution(s1)<<endl;
    cout << solution(s2) << endl;
}
