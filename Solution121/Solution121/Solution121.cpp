#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 여기 기존 solution 함수
long long solution(vector<int> weights) {
    long long answer = 0;
    unordered_map<int, int> weightjari;

    for (auto w : weights) {

        answer += weightjari[w];

        if (w % 3 == 0) answer += weightjari[w * 2 / 3];
        if (w % 2 == 0) answer += weightjari[w * 3 / 2];

        if (w % 4 == 0) answer += weightjari[w * 3 / 4];
        if (w % 3 == 0) answer += weightjari[w * 4 / 3];

        if (w % 2 == 0) answer += weightjari[w / 2];
        answer += weightjari[w * 2];

        weightjari[w]++;
    }
    return answer;
}

int main() {
    vector<int> weights = { 100, 180, 360, 100, 270 };
    long long result = solution(weights);
    cout << "Result: " << result << endl; // 예상: 4
    return 0;
}
