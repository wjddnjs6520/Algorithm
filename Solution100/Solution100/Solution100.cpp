#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int solution(int x, int y, int n) {
    vector<bool> visited(y + 1, false);
    queue<pair<int, int>> q; // {현재 값, 연산 횟수}

    q.push({ x, 0 });
    visited[x] = true;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        int value = cur.first;
        int count = cur.second;

        if (value == y) return count;

        // 세 가지 연산
        int next[3] = { value + n, value * 2, value * 3 };
        for (int nv : next) {
            if (nv <= y && !visited[nv]) {
                visited[nv] = true;
                q.push({ nv, count + 1 });
            }
        }
    }
    return -1;
}

int main() {
    cout << solution(10, 40, 5) << endl;   // 2
    cout << solution(10, 40, 30) << endl;  // 1
    cout << solution(2, 5, 4) << endl;     // -1
}
