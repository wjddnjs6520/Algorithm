#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    for (int i = 0; i < n; i++) {
        answer.push_back(x * (i + 1));
    }
    return answer;
}

int main()
{
    vector<long long> test1 = solution(2, 5);
    vector<long long> test2 = solution(4, 3);
    vector<long long> test3 = solution(-4, 2);
    for (int num : test1) {
        std::cout << num << ", ";
    }
    std::cout << endl;
    for (int num : test2) {
        std::cout << num << ", ";
    }
    std::cout << endl;
    for (int num : test3) {
        std::cout << num << ", ";
    }
    std::cout << endl;
}