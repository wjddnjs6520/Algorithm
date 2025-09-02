#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> cvec = { "aya", "ye", "woo", "ma" };

    for (string babble : babbling) {
        string prev = "";
        bool po = true;

        while (babble.size() > 0) {
            bool mach = false;
            for (string s : cvec) {
                if (babble.substr(0, s.size()) == s && prev != s) {
                    prev = s;
                    babble = babble.substr(s.size());
                    mach = true;
                    break;
                }
            }
            if (!mach) {
                po = false;
                break;
            }
        }
        if (po) answer++;
    }

    return answer;
}

int main() {
    vector<string> b1 = { "aya", "yee", "u", "maa" };
    vector<string> b2 = { "ayaye", "uuu", "yeye", "yemawoo", "ayaayaa" };
    cout << solution(b1) << endl;
    cout << solution(b2) << endl;
}
