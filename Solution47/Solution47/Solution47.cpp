#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    string tempstring = "";

    for (int i = 0; i < strings.size(); i++) {
        tempstring = strings[i];
        for (int j = i + 1; j < strings.size(); j++) {
            if (strings[i][n] > strings[j][n]) {//i 번째가 j 번째보다 크면 서로 교체
                tempstring = strings[i];
                strings[i] = strings[j];
                strings[j] = tempstring;
            }
            if (strings[i][n] == strings[j][n]) {
                if (strings[i] > strings[j]) {
                    tempstring = strings[i];
                    strings[i] = strings[j];
                    strings[j] = tempstring;
                }
            }
        }
        answer.push_back(strings[i]);
    }
    return answer;
}

int main()
{
    vector<string> s1 = { "sun", "bed", "car" };
    vector<string> s2 = { "abce", "abcd", "cdx" };
    
    vector<string> a1 = solution(s1, 1);
    vector<string> a2 = solution(s2, 2);

    for (string a : a1) {
        cout << a << " ";
    }
    cout << endl;
    for (string a : a2) {
        cout << a << " ";
    }
}
