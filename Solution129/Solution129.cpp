#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;

    // 1️⃣ Collatz 수열 생성
    vector<int> seq;
    seq.push_back(k);
    while (seq.back() != 1) {
        if (seq.back() % 2 == 0) seq.push_back(seq.back() / 2);
        else seq.push_back(seq.back() * 3 + 1);
    }

    int n = seq.size() - 1; // 마지막 x좌표

    // 2️⃣ prefix sum (사다리꼴 면적 누적)
    vector<double> prefix(n + 1, 0.0);
    for (int i = 1; i <= n; ++i)
        prefix[i] = prefix[i - 1] + (seq[i - 1] + seq[i]) / 2.0;

    // 3️⃣ 각 구간 적분 계산
    for (auto &r : ranges) {
        int a = r[0];
        int b = r[1];
        int start = a;
        int end = n + b;  // b가 음수면 끝에서부터 뺌

        if (start > end) { // 유효하지 않은 구간
            answer.push_back(-1.0);
        } else {
            double area = prefix[end] - prefix[start];
            answer.push_back(area);
        }
    }

    return answer;
}

int main() {
    // 🔹 테스트 1
    int k1 = 5;
    vector<vector<int>> ranges1 = {{0,0},{0,-1},{2,-3},{3,-3}};
    vector<double> result1 = solution(k1, ranges1);

    cout << "Test 1 (k = 5):" << endl;
    for (double v : result1) cout << v << " ";
    cout << "\nExpected: [33.0, 31.5, 0.0, -1.0]\n\n";

    // 🔹 테스트 2
    int k2 = 3;
    vector<vector<int>> ranges2 = {{0,0}, {1,-2}, {3,-3}};
    vector<double> result2 = solution(k2, ranges2);

    cout << "Test 2 (k = 3):" << endl;
    for (double v : result2) cout << v << " ";
    cout << "\nExpected: [47.0, 36.0, 12.0]\n";

    return 0;
}
