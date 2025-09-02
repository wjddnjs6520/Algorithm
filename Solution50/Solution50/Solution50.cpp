#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    string temp = "";
    for (int i = 0; i < s.size(); i++) {
        int a = -1;
        for (int j = 0; j < temp.size(); j++) {
            if (s[i] == temp[j]) {
                if (a < j) {
                    a = j;
                }

            }
        }
        if (a > -1) {
            answer.push_back(i - a);
        }
        else {
            answer.push_back(a);
        }
        temp += s[i];
    }
    return answer;
}
int main()
{
    vector<int> a1 = solution("banana");
    vector<int> a2 = solution("foobar");

    for (int i : a1) {
        cout << i << " ";
    }
    cout << endl;
    for (int i : a2) {
        cout << i << " ";
    }
}