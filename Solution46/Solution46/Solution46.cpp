#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string temp = "";

    for (char a : s) {
        if (a >= '0' && a <= '9') {
            answer = answer * 10 + (a - '0');
        }
        else {
            temp += a;

            if (temp == "zero") {
                answer = answer * 10 + 0;
                temp = "";
            }
            else if (temp == "one") {
                answer = answer * 10 + 1;
                temp = "";
            }
            else if (temp == "two") {
                answer = answer * 10 + 2;
                temp = "";
            }
            else if (temp == "three") {
                answer = answer * 10 + 3;
                temp = "";
            }
            else if (temp == "four") {
                answer = answer * 10 + 4;
                temp = "";
            }
            else if (temp == "five") {
                answer = answer * 10 + 5;
                temp = "";
            }
            else if (temp == "six") {
                answer = answer * 10 + 6;
                temp = "";
            }
            else if (temp == "seven") {
                answer = answer * 10 + 7;
                temp = "";
            }
            else if (temp == "eight") {
                answer = answer * 10 + 8;
                temp = "";
            }
            else if (temp == "nine") {
                answer = answer * 10 + 9;
                temp = "";
            }
        }
    }
    return answer;
}



int main()
{
    string s1 = "one4seveneight";
    string s2 = "23four5six7";
    string s3 = "2three45sixseven";
    string s4 = "123";
    cout << solution(s1) << endl;
    cout << solution(s2) << endl;
    cout << solution(s3) << endl;
    cout << solution(s4) << endl;
}
