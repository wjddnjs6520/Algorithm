#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    vector<int> temp;
    for (int i = 1; i < food.size(); ++i) {
        answer += std::string(food[i] / 2, '0' + i);
    }
    answer += "0";


    for (int j = food.size() - 1; j > 0; j--) {
        answer += std::string(food[j] / 2, '0' + j);
    }

    return answer;
}

int main()
{
    vector<int> f1 = { 1, 3, 4, 6 };
    vector<int> f2 = { 1, 7, 1, 2 };

    cout << solution(f1) << endl;
    cout << solution(f2);
}