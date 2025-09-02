#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    for (int i = 0; i < phone_number.size(); i++) {
        if (i < phone_number.size() - 4) {
            answer += "*";
        }
        else {
            answer += phone_number[i];
        }
    }
    return answer;
}

int main()
{
    string a1 = "01033334444";
    string a2 = "027778888";
    std::cout << solution(a1) << endl;
    std::cout << solution(a2) << endl;
}