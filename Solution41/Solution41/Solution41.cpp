#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    string temp = "";

    for (int i = 0; i < s.size(); i++) {
        temp += s[i];
        if (s[i] == ' ' || i == s.size() - 1) {
            for (int i = 0; i < temp.size(); i++) {
                if (i % 2 == 0) {
                    temp[i] = toupper(temp[i]);
                }
                else {
                    temp[i] = tolower(temp[i]);
                }
            }
            answer += temp;
            temp = "";
        }
    }
    return answer;
}

int main() {
    
    string s = "try hello world";

    cout << solution(s);

    return 0;
}
