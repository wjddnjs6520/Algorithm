#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int add = 0;
    bool abool = true;
    for (int i = 0; i < numbers.size() - 1; i++) {
        for (int j = 1; j < numbers.size(); j++) {
            if (i < j) {
                add = numbers[i] + numbers[j];
            }

            for (int k : answer) {
                if (add == k) {
                    abool = false;
                }
            }
            if (abool) {
                answer.push_back(add);
            }
            abool = true;
        }
    }
    int tempnumbers;
    for (int i = 0; i < answer.size(); i++) {
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
    vector<int> n1 = { 2, 1, 3, 4, 1 };
    vector<int> n2 = { 5, 0, 2, 7 };
    vector<int> a1 = solution(n1);
    vector<int> a2 = solution(n2);

    for (int a : a1) {
        cout << a << " ";
    }
    cout << endl;
    for (int a : a2) {
        cout << a << " ";
    }
}


