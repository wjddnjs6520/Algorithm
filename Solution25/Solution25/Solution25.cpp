#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    for (int a : arr) {
        if (a % divisor == 0) {
            answer.push_back(a);
        }
    }
    if (answer.size() < 1) {
        answer.push_back(-1);
    }
    int tempnumbers;
    for (int i = 0; i < answer.size(); i++) {
        tempnumbers = answer[i];
        for (int j = i + 1; j < answer.size(); j++) {
            if (answer[i] > answer[j]) {//i 번째가 j 번째보다 크면 서로 교체
                tempnumbers = answer[i];
                answer[i] = answer[j];
                answer[j] = tempnumbers;
            }
        }

    }
    return answer;
}

int main()
{
    vector<int> arr1 = { 5, 9, 7, 10 };
    vector<int> arr2 = { 2, 36, 1, 3 };
    vector<int> arr3 = { 3, 2, 6 };
    vector<int> aarr1 = solution(arr1, 5);
    vector<int> aarr2 = solution(arr2, 1);
    vector<int> aarr3 = solution(arr3, 10);
    for (int a : aarr1) {
        std::cout << a << " ";
    }
    std::cout << endl;
    for (int a : aarr2) {
        std::cout << a << " ";
    }
    std::cout << endl;
    for (int a : aarr3) {
        std::cout << a << " ";
    }
    std::cout << endl;
}