#include <iostream>
#include <vector>
using namespace std;

// 기존 solution 함수 선언
vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (auto x : numbers) {
        if (x % 2 == 0) {
            answer.push_back(x + 1);
        }
        else {
            long long bit = 1;
            while (x & bit) {
                bit <<= 1;
            }

            long long result = x + bit - (bit >> 1);
            answer.push_back(result);
        }
    }
    return answer;
}

int main() {
    vector<long long> numbers = { 2, 7 };
    vector<long long> result = solution(numbers);

    cout << "Result: ";
    for (auto r : result) {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}
