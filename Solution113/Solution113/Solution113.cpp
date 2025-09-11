#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int bfs(int start, int n, vector<vector<int>>& adj, int cutA, int cutB) {
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int count = 1;

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int next : adj[cur]) {
            if ((cur == cutA && next == cutB) || (cur == cutB && next == cutA)) continue;
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
                count++;
            }
        }
    }
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    vector<vector<int>> adj(n + 1);
    for (auto& w : wires) {
        adj[w[0]].push_back(w[1]);
        adj[w[1]].push_back(w[0]);
    }

    int answer = n;
    for (auto& w : wires) {
        int countA = bfs(w[0], n, adj, w[0], w[1]);
        int countB = n - countA;
        answer = min(answer, abs(countA - countB));
    }
    return answer;
}

int main() {
    cout << solution(9, { {1,3},{2,3},{3,4},{4,5},{4,6},{4,7},{7,8},{7,9} }) << endl; // 3
    cout << solution(4, { {1,2},{2,3},{3,4} }) << endl; // 0
    cout << solution(7, { {1,2},{2,7},{3,7},{3,4},{4,5},{6,7} }) << endl; // 1
    return 0;
}
