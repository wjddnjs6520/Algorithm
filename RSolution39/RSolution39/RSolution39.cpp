#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    if (n > m) {
        int temp = n;
        n = m;
        m = temp;
    }


    for (int i = n; i > 0; i--) {
        if (n % i == 0 && m % i == 0) {
            answer.push_back(i);
            break;
        }
    }

    for (int j = m; j < n * m + 1; j++) {
        if (j % n == 0 && j % m == 0) {
            answer.push_back(j);
            break;
        }
    }


    return answer;
}
int main()
{
    vector<int> a1 = solution(3, 12);
    vector<int> a2 = solution(2, 5);

    for (int a : a1) {
        cout << a << " ";
    }
    cout << endl;

    for (int a : a2) {
        cout << a << " ";
    }
    cout << endl;
}

