#include <iostream>
#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    for (int a : arr) {
        answer += a;
    }
    answer /= arr.size();
    return answer;
}

int main()
{
    vector<int> a1 = { 1, 2, 3, 4 };
    vector<int> a2 = { 5, 5 };
    cout << solution(a1) << endl;
    cout << solution(a2) << endl;
}
