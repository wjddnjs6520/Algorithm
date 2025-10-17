#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(vector<int> picks, vector<string> minerals) {

    int fatigue[3][3] = {
        {1, 1, 1},   // 다이아 곡괭이
        {5, 1, 1},   // 철 곡괭이
        {25, 5, 1}   // 돌 곡괭이
    };

    unordered_map<string, int> idx = { {"diamond",0},{"iron",1},{"stone",2} };


    int totalPicks = picks[0] + picks[1] + picks[2];
    if ((int)minerals.size() > totalPicks * 5) {
        minerals.resize(totalPicks * 5);
    }

    vector<pair<int, vector<int>>> groups;
    for (int i = 0; i < (int)minerals.size(); i += 5) {
        int score = 0;
        vector<int> g;
        for (int j = i; j < i + 5 && j < (int)minerals.size(); ++j) {
            int m = idx[minerals[j]];
            g.push_back(m);
            score += fatigue[2][m];
        }
        groups.push_back({ score, g });
    }


    sort(groups.begin(), groups.end(), [](const pair<int, vector<int>>& a, const pair<int, vector<int>>& b) {
        return a.first > b.first;
        });


    int ans = 0;
    for (const auto& gr : groups) {
        int pick = -1;
        for (int i = 0; i < 3; ++i) {
            if (picks[i] > 0) {
                pick = i;
                picks[i]--;
                break;
            }
        }
        if (pick == -1) break;

        for (int m : gr.second) {
            ans += fatigue[pick][m];
        }
    }

    return ans;
}

int main() {
    vector<int> picks1 = { 1, 3, 2 };
    vector<string> minerals1 = {
        "diamond","diamond","diamond","iron","iron",
        "diamond","iron","stone"
    };

    vector<int> picks2 = { 0, 1, 1 };
    vector<string> minerals2 = {
        "diamond","diamond","diamond","diamond","diamond",
        "iron","iron","iron","iron","iron","diamond"
    };

    cout << "Case1: " << solution(picks1, minerals1) << endl;
    cout << "Case2: " << solution(picks2, minerals2) << endl;

    return 0;
}