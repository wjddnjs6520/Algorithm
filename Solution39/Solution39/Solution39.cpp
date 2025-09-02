#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    if (m < n) {
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
    for (int i = m; i < n * m + 1; i++) {
        if (i % n == 0 && i % m == 0) {
            answer.push_back(i);
            break;
        }
    }
    return answer;
}

int main()
{
    vector<int> arr1 = solution(3, 12);
    vector<int> arr2 = solution(2, 5);
    for (int i : arr1) {
        cout << i << " ";
    }
    cout << endl;
    for (int i : arr2) {
        cout << i << " ";
    }
    cout << endl;
}