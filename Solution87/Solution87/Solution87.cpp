#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    for (long long i = left; i <= right; i++) {
        int value = max(i / n, i % n) + 1;
        answer.push_back(value);
    }


    return answer;
}

int main()
{
    vector<int> a1 = solution(3, 2, 5);
    vector<int> a2 = solution(4, 7, 14);

    for (int a : a1) {
        cout << a << " ";
    }
    cout << endl;
    for (int a : a2) {
        cout << a << " ";
    }
    cout << endl;


}

