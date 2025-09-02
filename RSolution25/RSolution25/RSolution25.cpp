#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    for (int a : arr) {
        if (a % divisor == 0) {
            answer.push_back(a);
        }
    }
    if (answer.size() > 0) {
        sort(answer.begin(), answer.end());
    }
    else {
        answer.push_back(-1);
    }

    return answer;
}

int main()
{
    vector<int> arr1 = { 5, 9, 7, 10 };
    vector<int> arr2 = { 2, 36, 1, 3 };
    vector<int> arr3 = { 3, 2, 6 };

    vector<int> a1 = solution(arr1, 5);
    vector<int> a2 = solution(arr2, 1);
    vector<int> a3 = solution(arr3, 10);

    for (int a : a1) {
        cout << a << " ";
    }
    cout << endl;

    for (int a : a2) {
        cout << a << " ";
    }
    cout << endl;

    for (int a : a3) {
        cout << a << " ";
    }
    cout << endl;
}

