#include <iostream>
#include <vector>
#include <string>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    for (int num : arr) {
        answer += num;
    }
    answer /= arr.size();
    return answer;
}

int main()
{
    vector<int> arr1 = { 1, 2, 3, 4};
    vector<int> arr2 = { 5, 5};
    cout << solution(arr1) << endl;
    cout << solution(arr2) << endl;
}
