#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    vector<int> nvector(n);
    for (int a : section) {
        nvector[a - 1] = 1;
    }

    for (int i = 0; i < nvector.size(); i++) {
        if (nvector[i] == 1) {
            for (int j = i; j < i + m && j < nvector.size(); j++) {
                nvector[j] = 1;
            }
            answer++;
            i = i + m - 1;
        }


    }
    return answer;
}

int main()
{
    vector<int> s1 = { 2, 3, 6 };
    vector<int> s2 = { 1, 3 };
    vector<int> s3 = { 1, 2, 3, 4 };
    cout << solution(8, 4, s1) << endl;
    cout << solution(5, 4, s2) << endl;
    cout << solution(4, 1, s3) << endl;
}
