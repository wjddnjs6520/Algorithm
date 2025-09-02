#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> temp;
    for (int i = 0; i < ingredient.size(); i++) {
        temp.push_back(ingredient[i]);

        if (temp.size() >= 4 && temp[temp.size() - 1] == 1
            && temp[temp.size() - 2] == 3 && temp[temp.size() - 3] == 2
            && temp[temp.size() - 4] == 1) {
            answer++;
            temp.pop_back();
            temp.pop_back();
            temp.pop_back();
            temp.pop_back();
        }
    }
    return answer;
}

int main()
{
    vector<int> i1 = { 2, 1, 1, 2, 3, 1, 2, 3, 1 };
    vector<int> i2 = { 1, 3, 2, 1, 2, 1, 3, 1, 2 };

    cout << solution(i1) << endl;
    cout << solution(i2) << endl;
}