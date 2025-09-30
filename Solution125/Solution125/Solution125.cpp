#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> cards) {
    int answer = 0;

    vector<int> group;
    vector<bool> visited(cards.size(), false);

    for (int i = 0; i < cards.size(); i++) {
        if (visited[i] == true) continue;

        vector<int> temp;
        int next = i;
        while (visited[next] != true) {
            temp.push_back(cards[next]);
            visited[next] = true;
            next = cards[next] - 1;
        }

        group.push_back(temp.size());
    }

    sort(group.begin(), group.end(), greater<int>());

    if (group.size() < 2) {
        answer = 0;
    }
    else {
        answer = group[0] * group[1];
    }

    return answer;
}

int main() {
    vector<int> cards = { 8, 6, 3, 7, 2, 5, 1, 4 };

    int result = solution(cards);
    cout << "Result: " << result << endl;  // 예상 출력: 12

    return 0;
}
