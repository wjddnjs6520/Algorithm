#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// 앞서 작성한 solution 함수
struct Node {
    int y, x, move;
};

int dy[4] = { -1, 1, 0, 0 }; // 상, 하, 좌, 우
int dx[4] = { 0, 0, -1, 1 };

int solution(vector<string> board) {
    int h = board.size();
    int w = board[0].size();

    int startY, startX, goalY, goalX;
    vector<vector<bool>> visited(h, vector<bool>(w, false));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (board[i][j] == 'R') { startY = i; startX = j; }
            if (board[i][j] == 'G') { goalY = i; goalX = j; }
        }
    }

    queue<Node> q;
    q.push({ startY, startX, 0 });
    visited[startY][startX] = true;

    while (!q.empty()) {
        Node cur = q.front(); q.pop();

        if (cur.y == goalY && cur.x == goalX) return cur.move;

        for (int dir = 0; dir < 4; dir++) {
            int ny = cur.y;
            int nx = cur.x;

            while (true) {
                int ty = ny + dy[dir];
                int tx = nx + dx[dir];

                if (ty < 0 || ty >= h || tx < 0 || tx >= w) break;
                if (board[ty][tx] == 'D') break;

                ny = ty;
                nx = tx;
            }

            if (visited[ny][nx]) continue;

            visited[ny][nx] = true;
            q.push({ ny, nx, cur.move + 1 });
        }
    }

    return -1;
}

int main() {
    vector<vector<string>> boards = {
        {"...D..R", ".D.G...", "....D.D", "D....D.", "..D...."},
        {".D.R", "....", ".G..", "...D"}
    };

    for (auto& b : boards) {
        cout << solution(b) << endl;
    }

    return 0;
}
