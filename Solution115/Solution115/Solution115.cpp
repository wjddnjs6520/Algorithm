#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// "HH:MM" → 분 단위 변환
int toMinutes(const string& time) {
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    return h * 60 + m;
}

int solution(vector<vector<string>> book_time) {
    vector<pair<int, int>> times;
    for (auto& t : book_time) {
        int start = toMinutes(t[0]);
        int end = toMinutes(t[1]) + 10; // 퇴실 후 10분 청소
        times.push_back({ start, end });
    }

    // 시작 시간 기준 정렬
    sort(times.begin(), times.end());

    // 우선순위 큐 (최소 힙)
    priority_queue<int, vector<int>, greater<int>> pq;

    for (auto& t : times) {
        int start = t.first;
        int end = t.second;

        if (!pq.empty() && pq.top() <= start) {
            pq.pop(); // 방 재사용
        }
        pq.push(end);
    }

    return pq.size(); // 필요한 방 개수
}

int main() {
    vector<vector<string>> test1 = {
        {"15:00", "17:00"},
        {"16:40", "18:20"},
        {"14:20", "15:20"},
        {"14:10", "19:20"},
        {"18:20", "21:20"}
    };
    vector<vector<string>> test2 = {
        {"09:10", "10:10"},
        {"10:20", "12:20"}
    };
    vector<vector<string>> test3 = {
        {"10:20", "12:30"},
        {"10:20", "12:30"},
        {"10:20", "12:30"}
    };

    cout << "Test1 result = " << solution(test1) << " (기대값: 3)" << endl;
    cout << "Test2 result = " << solution(test2) << " (기대값: 1)" << endl;
    cout << "Test3 result = " << solution(test3) << " (기대값: 3)" << endl;

    return 0;
}
