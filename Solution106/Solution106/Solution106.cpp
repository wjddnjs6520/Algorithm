#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    vector<int> bozo;
    int idx = 1;

    for (int j = 0; j < order.size(); j++)
    {
        if (order[j] == idx)
        {
            idx++;
            answer++;
        }
        else if (order[j] > idx)
        {
            for (int k = idx; k < order[j]; k++)
            {
                // 이미 보조 컨테이너나 전달된 값이 아니면 넣기
                bozo.push_back(k);
            }
            // idx는 order[j]를 전달한 후에만 증가
            answer++;
            idx = order[j] + 1;
        }
        else if (!bozo.empty() && order[j] == bozo.back())
        {
            bozo.pop_back();
            answer++;
        }
        else
        {
            break;
        }
    }

    return answer;
}

int main() {
    vector<int> order1 = { 4, 3, 1, 2, 5 };
    int ans1 = solution(order1);
    cout << "최종 answer: " << ans1 << endl;

    vector<int> order2 = { 5, 4, 3, 2, 1 };
    int ans2 = solution(order2);
    cout << "최종 answer: " << ans2 << endl;
    return 0;
}
