#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> nvector(n, 1);

    for (int i = 0; i < lost.size(); i++) {
        nvector[lost[i] - 1] = 0;
    }

    for (int j = 0; j < reserve.size(); j++) {
        nvector[reserve[j] - 1]++;
    }

    for (int k = 0; k < nvector.size(); k++) {
        if (nvector[k] > 0) {
            answer++;
        }
        else {
            if ((k - 1) >= 0 && nvector[k - 1] > 1) {
                nvector[k - 1]--;
                nvector[k] = 1;
                answer++;
            }
            else if ((k + 1) < nvector.size() && nvector[k + 1] > 1) {
                nvector[k + 1]--;
                nvector[k] = 1;
                answer++;
            }
        }
    }

    return answer;
}
int main()
{
    vector<int> l1 = { 2, 4 };
    vector<int> l2 = { 2, 4 };
    vector<int> l3 = { 3 };
    vector<int> r1 = { 1, 3, 5 };
    vector<int> r2 = { 3 };
    vector<int> r3 = { 1 };

    
    cout << solution(5, l1, r1) << endl;
    cout << solution(5, l2, r2) << endl;
    cout << solution(3, l3, r3) << endl;
}
