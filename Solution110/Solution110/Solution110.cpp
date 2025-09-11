#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long long total = 0;

    queue<int> q1, q2;
    long long sum1 = 0, sum2 = 0;

    for (int x : queue1) {
        q1.push(x);
        sum1 += x;
    }
    for (int x : queue2) {
        q2.push(x);
        sum2 += x;
    }

    total = sum1 + sum2;

    if (total % 2 == 1) {
        return -1;
    }

    long long max_answer = (queue1.size() + queue2.size()) * 2; // 안전하게 2배

    while (sum1 != total / 2 && sum2 != total / 2) {
        if (sum1 > total / 2) {
            int n = q1.front();
            q1.pop();
            q2.push(n);
            sum1 -= n;
            sum2 += n;
            answer++;
        }
        else {
            int n = q2.front();
            q2.pop();
            q1.push(n);
            sum2 -= n;
            sum1 += n;
            answer++;
        }

        if (answer > max_answer) {
            answer = -1;
            break;
        }
    }

    return answer;
}

int main() {
    vector<int> q1, q2;

    // 테스트 케이스 1
    q1 = { 3, 2, 7, 2 };
    q2 = { 4, 6, 5, 1 };
    cout << "결과1: " << solution(q1, q2)  << endl;

    // 테스트 케이스 2
    q1 = { 1, 2, 1, 2 };
    q2 = { 1, 10, 1, 2 };
    cout << "결과2: " << solution(q1, q2)  << endl;

    // 테스트 케이스 3
    q1 = { 1, 1 };
    q2 = { 1, 5 };
    cout << "결과3: " << solution(q1, q2)  << endl;

    return 0;
}
