#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int delivery(int N, const vector<vector<int>>& road, int K) {
    vector<vector<pair<int, int>>> graph(N + 1);

    // 인접 리스트 구성
    for (auto& r : road) {
        int u = r[0], v = r[1], w = r[2];
        graph[u].push_back({ v, w });
        graph[v].push_back({ u, w });
    }

    // 최단거리 배열
    vector<int> dist(N + 1, 1e9);
    dist[1] = 0; // 시작은 마을 1

    // 다익스트라 우선순위 큐
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, 1 }); // (거리, 노드)

    while (!pq.empty()) {
        pair<int, int> top = pq.top(); // 구조분해 대신
        int d = top.first;
        int cur = top.second;
        pq.pop();

        if (d > dist[cur]) continue;

        for (auto& edge : graph[cur]) {
            int next = edge.first;
            int cost = edge.second;

            if (dist[next] > d + cost) {
                dist[next] = d + cost;
                pq.push(make_pair(dist[next], next));
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i] <= K) answer++;
    }
    return answer;
}

int main() {
    vector<vector<int>> road1 = {
        {1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2}
    };
    int N1 = 5, K1 = 3;
    cout << delivery(N1, road1, K1) << endl; // 기대값: 4

    vector<vector<int>> road2 = {
        {1,2,1},{1,3,2},{2,3,2},{3,4,3},{3,5,2},{3,5,3},{5,6,1}
    };
    int N2 = 6, K2 = 4;
    cout << delivery(N2, road2, K2) << endl; // 기대값: 4

    return 0;
}
