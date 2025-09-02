#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int solution(vector<int> topping) {
    unordered_map<int, int> rightCount;
    unordered_set<int> leftSet;

    for (int t : topping) {
        rightCount[t]++;
    }

    int rightKinds = rightCount.size();
    int leftKinds = 0;
    int answer = 0;

    for (int i = 0; i < topping.size(); i++) {
        int t = topping[i];

        // 왼쪽에 추가
        if (leftSet.find(t) == leftSet.end()) {
            leftSet.insert(t);
            leftKinds++;
        }

        // 오른쪽에서 제거
        rightCount[t]--;
        if (rightCount[t] == 0) {
            rightKinds--;
        }

        // 토핑 수 비교
        if (leftKinds == rightKinds) {
            answer++;
        }
        else if (leftKinds > rightKinds)
        {
            break;
        }
    }
    return answer;
}

int main() {
    vector<vector<int>> testCases = {
        {1, 2, 1, 3, 1, 4, 1, 2},
        {1, 2, 3, 1, 4}
    };

    for (auto& topping : testCases) {
        cout << "topping: [";
        for (int i = 0; i < topping.size(); i++) {
            cout << topping[i];
            if (i != topping.size() - 1) cout << ", ";
        }
        cout << "]\n";

        int result = solution(topping);
        cout << "result: " << result << "\n\n";
    }

    return 0;
}
