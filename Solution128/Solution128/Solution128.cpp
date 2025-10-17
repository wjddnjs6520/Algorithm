#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

// 디펜스 게임 솔루션 함수
int solution(int n, int k, vector<int> enemy) {
    priority_queue<int> pq;  // 현재까지 등장한 적 수 (최대 힙)

    for (int i = 0; i < enemy.size(); i++) {
        n -= enemy[i];        // 병사 소모
        pq.push(enemy[i]);    // 이번 라운드 적 추가

        if (n < 0) {          // 병사 부족하면
            if (k > 0 && !pq.empty()) {
                n += pq.top(); // 가장 많은 적 라운드 무적 처리
                pq.pop();
                k--;
            }
            else {
                return i;      // 더 이상 막을 수 없으면 종료
            }
        }
    }

    return enemy.size();      // 모든 라운드 막음
}

// 테스트용 메인 함수
int main() {
    cout << "테스트 1 → " << solution(7, 3, { 4, 2, 4, 5, 3, 3, 1 }) << endl; // 결과: 5
    cout << "테스트 2 → " << solution(2, 4, { 3, 3, 3, 3 }) << endl;         // 결과: 4
    return 0;
}
