#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> bridge;
    int totalWeight = 0;
    int idx = 0;

    for (int i = 0; i < bridge_length; i++)
    {
        bridge.push(0);
    }

    while (!bridge.empty())
    {
        answer++;
        totalWeight -= bridge.front();
        bridge.pop();

        if (idx < truck_weights.size())
        {
            if (totalWeight + truck_weights[idx] <= weight)
            {
                bridge.push(truck_weights[idx]);
                totalWeight += truck_weights[idx];
                idx++;
            }
            else {
                bridge.push(0);
            }
        }
    }


    return answer;
}

int main() {
    // 테스트 케이스
    cout << solution(2, 10, { 7, 4, 5, 6 }) << endl; // 8
    cout << solution(100, 100, { 10 }) << endl;      // 101
    cout << solution(100, 100, { 10,10,10,10,10,10,10,10,10,10 }) << endl; // 110

    return 0;
}
