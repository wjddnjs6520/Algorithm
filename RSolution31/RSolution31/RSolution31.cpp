#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    bool bn = true;

    for (int i = 0; i < n; i++) {
        if (bn) {
            answer += "수";
            bn = false;
        }
        else {
            answer += "박";
            bn = true;
        }
    }

    return answer;
}

int main()
{
    std::cout << solution(3) << endl;
    std::cout << solution(4) << endl;
}

