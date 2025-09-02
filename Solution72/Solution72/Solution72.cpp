#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer = players;
    unordered_map<string, int> pos;

    for (int i = 0; i < answer.size(); i++) {
        pos[answer[i]] = i;
    }

    for (int j = 0; j < callings.size(); j++) {
        int idx = pos[callings[j]];

        string& curr = answer[idx];
        string& prev = answer[idx - 1];

        swap(curr, prev);

        pos[curr] = idx;
        pos[prev] = idx - 1;

    }

    return answer;
}

int main()
{
    vector<string> p1 = { "mumu", "soe", "poe", "kai", "mine" };
    vector<string> c1 = { "kai", "kai", "mine", "mine" };
    vector<string> a1 = solution(p1, c1);

    for (string s : a1) {
        cout << s << " ";
    }
    cout << endl;
}


