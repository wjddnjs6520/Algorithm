#include <vector>
#include <iostream>
using namespace std;

void hanoi(int n, int start, int mid, int end, vector<vector<int>>& answer) {
    if (n == 1) {
        answer.push_back({ start, end });
        return;
    }

    hanoi(n - 1, start, end, mid, answer);
    answer.push_back({ start, end });
    hanoi(n - 1, mid, start, end, answer);
}


vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(n, 1, 2, 3, answer);
    return answer;
}


int main() {
    int n = 2;
    auto moves = solution(n);

    cout << "총 이동 횟수: " << moves.size() << '\n';
    for (const auto& m : moves) {
        cout << m[0] << " -> " << m[1] << '\n';
    }
    return 0;
}
