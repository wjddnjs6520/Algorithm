#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;

    sort(data.begin(), data.end(), [col](const vector<int>& a, const vector<int>& b) {
        if (a[col - 1] == b[col - 1]) return a[0] > b[0];
        return a[col - 1] < b[col - 1];
        });

    for (int i = row_begin; i <= row_end; i++) {
        int S_i = 0;
        for (int j = 0; j < data[i - 1].size(); j++) {
            S_i += data[i - 1][j] % i;
        }
        answer ^= S_i;
    }

    return answer;
}

int main() {
    vector<vector<int>> data = {
        {2, 2, 6},
        {1, 5, 10},
        {4, 2, 9},
        {3, 8, 3}
    };

    int col = 2;
    int row_begin = 2;
    int row_end = 3;

    int result = solution(data, col, row_begin, row_end);
    cout << "Result: " << result << endl;  // 기대 출력: 4

    return 0;
}
