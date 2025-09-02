#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> qurprior;
    priority_queue<int> pq;

    for (int i = 0; i < priorities.size(); i++) {
        qurprior.push({ priorities[i], i });
        pq.push(priorities[i]);
    }

    while (!qurprior.empty()) {
        auto front = qurprior.front();
        qurprior.pop();

        if (front.first == pq.top()) {
            pq.pop();
            answer++;
            if (front.second == location) break;
        }
        else {
            qurprior.push(front);
        }
    }
    return answer;
}

int main()
{
    vector<int> p1 = { 2, 1, 3, 2 };
    vector<int> p2 = { 1, 1, 9, 1, 1, 1 };

    cout << solution(p1, 2) << endl;
    cout << solution(p2, 0) << endl;
}

