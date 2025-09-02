#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    for (int i = 0; i < number.size() - 2; i++) {
        for (int j = 1; j < number.size() - 1; j++) {
            for (int k = 2; k < number.size(); k++) {
                int a = number[i] + number[j] + number[k];
                if (a == 0 && (i < j) && (j < k)) {
                    answer++;
                }
            }
        }
    }
    return answer;
}

int main()
{
    vector<int> v1 = {-2,3, 0, 2, -5};
    vector<int> v2 = { -3, -2, -1, 0, 1, 2, 3 };
    vector<int> v3 = { -1, 1, -1, 1 };

    cout << solution(v1)<< endl;
    cout << solution(v2) << endl;
    cout << solution(v3) << endl;
}
