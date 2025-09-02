#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    vector<int> temp;
    for (int i = 1; i < food.size(); i++) {
        temp.push_back(food[i] / 2);
    }

    for (int i = 0; i < temp.size(); i++) {
        for (int j = 0; j < temp[i]; j++) {
            answer += to_string((i + 1));
        }
    }
    answer += '0';
    for (int i = temp.size() - 1; i >= 0; i--) {
        for (int j = temp[i]; j > 0; j--) {
            answer += to_string((i + 1));
        }
    }

    return answer;
}

int main()
{
    vector<int> v1 = { 1, 3, 4, 6 };
    vector<int> v2 = { 1, 7, 1, 2 };
    cout << solution(v1) << endl;
    cout << solution(v2) << endl;
}
