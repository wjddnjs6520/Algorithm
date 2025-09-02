#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min = arr[0];
    for (int a : arr) {
        if (min > a) {
            min = a;
        }
    }
    for (int a : arr) {
        if (a == min) {

        }
        else {
            answer.push_back(a);
        }
    }

    if (answer.size() == 0) {
        answer.push_back(-1);
    }

    return answer;
}
int main()
{
    vector<int> v1 = { 4, 3, 2, 1 };
    vector<int> v2 = { 10 };
    vector<int> sv1 = solution(v1);
    vector<int> sv2 = solution(v2);

    for (int a : sv1) {
        cout << a << " ";
    }
    cout << endl;
    for (int a : sv2) {
        cout << a << " ";
    }
}
