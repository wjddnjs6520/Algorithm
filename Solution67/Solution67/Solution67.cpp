#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    for (char c : s) {
        for (int i = 0; i < index; i++) {
            c = (c - 'a' + 1) % 26 + 'a';
            while (skip.find(c) != string::npos) {
                c = (c - 'a' + 1) % 26 + 'a';
            }
        }
        answer += c;
    }
    return answer;
}

int main()
{
    std::cout <<solution("aukks", "wbqd", 5);
}

