#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    int a = score.size();
    vector<int> temp(k+1, 0);
    for (int i = 0; i < score.size(); i++) {
        temp[score[i]] = temp[score[i]] + 1;
    }

    int remain = 0;

    for (int i = k; i > 0; i--) {
        remain += temp[i];

        while (remain >= m) {
            answer += i * m;
            remain -= m;
        }
    }

    return answer;
}

int main()
{
    vector<int> s1 = { 1, 2, 3, 1, 2, 3, 1 };
    vector<int> s2 = { 4, 1, 2, 2, 4, 4, 4, 4, 1, 2, 4, 2 };
    cout << solution(3, 4, s1) << endl;
    cout << solution(4, 3, s2) << endl;
}
