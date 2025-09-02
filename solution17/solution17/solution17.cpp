#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    while (n > 10) {
        int temp = n % 10;
        answer.push_back(temp);
        n = n / 10;
    }
    answer.push_back(n);
    return answer;
}
int main()
{
    vector<int> answwer1 = solution(12345);
    for (int i : answwer1) {
        cout << i << ", ";
    }
}