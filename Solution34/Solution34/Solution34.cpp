#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int tempnumbers;
    for (int i = 0; i < s.size(); i++) {
        for (int j = i + 1; j < s.size(); j++) {
            if (s[i] < s[j]) {//i번째가 j번째 보다 작으면 서로 교체
                tempnumbers = s[i];
                s[i] = s[j];
                s[j] = tempnumbers;
            }
        }
    }
    answer = s;
    return answer;
}

int main()
{
    std::cout <<solution("Zbcdefg");
}
