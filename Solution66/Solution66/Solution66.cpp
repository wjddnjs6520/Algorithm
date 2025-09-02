#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    for (string s : targets) {
        int num = 0;
        for (char c : s) {
            vector<int> kvec;
            for (string ks : keymap) {
                for (int k = 0; k < ks.size(); k++) {
                    if (ks[k] == c) {
                        kvec.push_back(k + 1);
                    }
                }
            }
            if (kvec.empty()) {
                num = -1;
                break;
            }
            else {
                sort(kvec.begin(), kvec.end());
                num += kvec[0];
            }

        }
        answer.push_back(num);
    }
    return answer;
}

int main()
{
    vector<string> k1 = { "ABACD", "BCEFD" };
    vector<string> k2 = { "AA" };
    vector<string> k3 = { "AGZ", "BSSS" };
    vector<string> t1 = { "ABCD","AABB" };
    vector<string> t2 = { "B" };
    vector<string> t3 = { "ASA","BGZ" };
    
    vector<int> a1 = solution(k1, t1);
    vector<int> a2 = solution(k2, t2);
    vector<int> a3 = solution(k3, t3);

    for (int a : a1) {
        cout << a << " ";
    }
    cout << endl;

    for (int a : a2) {
        cout << a << " ";
    }
    cout << endl;

    for (int a : a3) {
        cout << a << " ";
    }
    cout << endl;

}
