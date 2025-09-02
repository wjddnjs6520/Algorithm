#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> s1 = { 1, 2, 3, 4, 5 };
    vector<int> s2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> s3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    vector<int> count(3, 0);

    for (int i = 0; i < answers.size(); i++) {
        if (s1[i % 5] == answers[i]) {
            count[0] += 1;
        }
        if (s2[i % 8] == answers[i]) {
            count[1] += 1;
        }
        if (s3[i % 10] == answers[i]) {
            count[2] += 1;
        }
    }
    int max = 0;
    for (int j = 0; j < count.size(); j++) {
        if (max < count[j]) {
            max = count[j];
        }
    }

    for (int k = 0; k < count.size(); k++) {
        if (count[k] == max) {
            answer.push_back(k + 1);
        }
    }

    return answer;
}

int main()
{
    vector<int> a1 = { 1, 2, 3,4, 5 };
    vector<int> a2 = { 1, 3, 2,4, 2 };
    vector<int> r1 = solution(a1);
    vector<int> r2 = solution(a2);

    for (int r : r1) {
        cout << r << " ";
    }
    cout << endl;

    for (int r : r2) {
        cout << r << " ";
    }
    cout << endl;

}

