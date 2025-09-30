#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

int bfs(vector<string>& maps, pair<int, int> start, pair<int, int> end)
{
    int n = maps.size();
    int m = maps[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<tuple<int, int, int>> q;

    q.push(make_tuple(start.first, start.second, 0));
    visited[start.first][start.second] = true;

    int dy[4] = { -1, 1, 0, 0 };
    int dx[4] = { 0, 0, -1, 1 };

    while (!q.empty())
    {
        int y, x, d;
        tie(y, x, d) = q.front(); // 구조분해 대신 tie
        q.pop();

        if (y == end.first && x == end.second) return d;

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (!visited[ny][nx] && maps[ny][nx] != 'X')
            {
                visited[ny][nx] = true;
                q.push(make_tuple(ny, nx, d + 1));
            }
        }
    }
    return -1;
}

int solution(vector<string> maps) {
    int n = maps.size();
    int m = maps[0].size();

    pair<int, int> start, lever, end;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (maps[i][j] == 'S') start = { i, j };
            else if (maps[i][j] == 'L') lever = { i, j };
            else if (maps[i][j] == 'E') end = { i, j };
        }
    }

    int dist1 = bfs(maps, start, lever);
    int dist2 = bfs(maps, lever, end);

    if (dist1 == -1 || dist2 == -1) return -1;
    return dist1 + dist2;
}

int main() {
    vector<string> maps1 = {
        "SOOOL",
        "XXXXO",
        "OOOOO",
        "OXXXX",
        "OOOOE"
    };
    cout << solution(maps1) << "\n"; // 16

    vector<string> maps2 = {
        "LOOXS",
        "OOOOX",
        "OOOOO",
        "OOOOO",
        "EOOOO"
    };
    cout << solution(maps2) << "\n"; // -1

    return 0;
}
