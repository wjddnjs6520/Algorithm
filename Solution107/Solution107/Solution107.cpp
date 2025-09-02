#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    for (char c : number)
    {
        while (!answer.empty() && k > 0 && answer.back() < c)
        {
            answer.pop_back();
            k--;
        }
        answer.push_back(c);
    }

    return answer.substr(0, answer.size() - k);
}

int main() {
    string number1 = "1924";
    string number2 = "1231234";
    string number3 = "4177252841";

    cout << solution(number1, 2) << endl;
    cout << solution(number2, 3) << endl;
    cout << solution(number3, 4) << endl;
}

