#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    long long multi = 1;
    bool tn = true;
    for (int a : arr) {
        multi = multi * a;
    }

    for (int i = 1; i <= multi; i++) {
        for (int a : arr) {
            if (i % a != 0) {
                tn = false;
                break;
            }
        }

        if (tn) {
            answer = i;
            break;
        }
        tn = true;

    }

    return answer;
}

int main()
{
    vector<int> a1 = { 2, 6, 8, 14 };
    vector<int> a2 = { 1, 2, 3 };

    cout << solution(a1) << endl;
    cout << solution(a2) << endl;
}
