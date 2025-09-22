#include <iostream>
#include <string>
#include <vector>

using namespace std;

int check(vector<string>& place)
{
    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };
    int diag[4][2] = { {1, 1}, {1, -1}, {-1, 1}, {-1,-1} };

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (place[i][j] != 'P') continue;

            // 거리 1 확인
            for (int k = 0; k < 4; k++)
            {
                int nexti = i + dx[k];
                int nextj = j + dy[k];
                if (nexti < 0 || nextj < 0 || nexti >= 5 || nextj >= 5) continue;
                if (place[nexti][nextj] == 'P') return 0;
            }

            // 직선 거리 2 확인
            for (int k = 0; k < 4; k++)
            {
                int nexti = i + dx[k];
                int nextj = j + dy[k];
                int next2i = i + dx[k] * 2;
                int next2j = j + dy[k] * 2;
                if (next2i < 0 || next2j < 0 || next2i >= 5 || next2j >= 5) continue;
                if (place[next2i][next2j] == 'P' && place[nexti][nextj] != 'X') return 0;
            }

            // 대각선 확인
            for (int k = 0; k < 4; k++)
            {
                int nexti = i + diag[k][0];
                int nextj = j + diag[k][1];
                if (nexti < 0 || nextj < 0 || nexti >= 5 || nextj >= 5) continue;
                if (place[nexti][nextj] == 'P')
                {
                    if (place[nexti][j] != 'X' || place[i][nextj] != 'X') return 0;
                }
            }
        }
    }

    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (auto& place : places)
    {
        answer.push_back(check(place));
    }
    return answer;
}

int main() {
    vector<vector<string>> places = {
        {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
        {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
        {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
        {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
        {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}
    };

    vector<int> result = solution(places);

    cout << "[";
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
