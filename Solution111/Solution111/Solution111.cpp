#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dfs(vector<string>& maps, vector<vector<bool>>& visit, int x, int y) {
    int h = maps.size();
    int w = maps[0].size();

    visit[x][y] = true;
    int sum = maps[x][y] - '0';

    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
            if (!visit[nx][ny] && maps[nx][ny] != 'X') {
                sum += dfs(maps, visit, nx, ny);
            }
        }
    }
    return sum;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int h = maps.size();
    int w = maps[0].size();

    vector<vector<bool>> visit(h, vector<bool>(w, false));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!visit[i][j] && maps[i][j] != 'X') {
                answer.push_back(dfs(maps, visit, i, j));
            }
        }
    }

    if (answer.empty()) {
        answer.push_back(-1);
    }
    else {
        sort(answer.begin(), answer.end());
    }
    return answer;
}

int main() {
    vector<string> maps1 = { "X591X","X1X5X","X231X", "1XXX1" };
    vector<string> maps2 = { "XXX","XXX","XXX" };

    vector<int> result1 = solution(maps1);
    vector<int> result2 = solution(maps2);

    cout << "Result 1: ";
    for (int v : result1) cout << v << " ";
    cout << endl;

    cout << "Result 2: ";
    for (int v : result2) cout << v << " ";
    cout << endl;

    return 0;
}
