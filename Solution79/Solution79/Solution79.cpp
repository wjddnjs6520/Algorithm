#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown + yellow;

    for (int h = 3; h <= total; h++) {
        if (total % h == 0) {
            int w = total / h;

            if ((h - 2) * (w - 2) == yellow) {
                answer.push_back(w);
                answer.push_back(h);
                return answer;
            }

        }
    }

    return answer;
}

int main()
{
    vector<int> a1 = solution(10, 2);
    vector<int> a2 = solution(8, 1);
    vector<int> a3 = solution(24, 24);


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

