#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int n = sequence.size();
    int left = 0, right = 0;
    long long sum = sequence[0];

    int bestL = 0, bestR = n - 1;
    int bestLen = n;

    while (left < n && right < n) {
        if (sum == k) {
            int len = right - left;
            if (len < bestLen || (len == bestLen && left < bestL)) {
                bestLen = len;
                bestL = left;
                bestR = right;
            }
            sum -= sequence[left];
            left++;
        }
        else if (sum < k) {
            right++;
            if (right < n) sum += sequence[right];
        }
        else { // sum > k
            sum -= sequence[left];
            left++;
        }
    }

    return { bestL, bestR };
}

int main() {
    vector<vector<int>> sequences = {
        {1, 2, 3, 4, 5},
        {1, 1, 1, 2, 3, 4, 5},
        {2, 2, 2, 2, 2}
    };
    vector<int> ks = { 7, 5, 6 };

    for (int i = 0; i < sequences.size(); i++) {
        vector<int> result = solution(sequences[i], ks[i]);
        cout << "Test " << i + 1 << ": ["
            << result[0] << ", " << result[1] << "]" << endl;
    }
    return 0;
}
