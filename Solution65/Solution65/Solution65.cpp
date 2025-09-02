#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;

    while (!s.empty()) {
        char first = s[0];
        int fnum = 0;
        int onum = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == first) {
                fnum++;
            }
            else {
                onum++;
            }
            //cout << "fnum: " << fnum << " onum: " << onum << endl;
            if (fnum == onum) {
                answer++;
                //cout << "substr: " << s.substr(0, i+1) << endl;
                s = s.substr(i+1);
                //cout << "s: " << s << endl;
                break;
            }
            if (i == s.size() - 1) {
                answer++;
                //cout << "substr: " << s.substr(i+1) << endl;
                s = "";
            }
        }
    }
    return answer;
}

int main()
{
    cout << solution("banana") << endl;
    cout << solution("abracadabra") << endl;
    cout << solution("aaabbaccccabba") << endl;
}

