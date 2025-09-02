#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<int> xnum(10);
    vector<int> ynum(10);
    vector<int> xynum(10);

    for (char c : X) {
        xnum[c - '0']++;
    }
    for (char c : Y) {
        ynum[c - '0']++;
    }

    for (int i = 0; i < xynum.size(); i++) {
        if (xnum[i] != 0 && ynum[i] != 0) {
            if (xnum[i] > ynum[i]) {
                xynum[i] = ynum[i];
            }
            else {
                xynum[i] = xnum[i];
            }
        }
    }

    for (int j = xynum.size()-1; j >= 0; j--) {
        while (xynum[j] > 0) {
            xynum[j]--;
            answer += to_string(j);
        }
    }

    if (answer == "") {
        answer = "-1";
    }
    if (answer[0]=='0') {
        answer = "0";
    }

    return answer;
}

int main()
{
    cout << solution("100", "2345") << endl;
    cout << solution("100",	"203045") << endl;
    cout << solution("100",	"123450") << endl;
    cout << solution("12321", "42531") << endl;
    cout << solution("5525", "1255") << endl;    	
}

