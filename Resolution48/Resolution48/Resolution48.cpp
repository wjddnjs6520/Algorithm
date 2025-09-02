#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;

    for (int i = 0; i < commands.size(); i++)
    {
        temp.assign(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1]);
        sort(temp.begin(), temp.end());
        answer.push_back(temp[commands[i][2] - 1]);
        temp.clear();
    }

    return answer;
}

int main()
{
    vector<int> array1 = { 1, 5, 2, 6, 3, 7, 4 };
    vector<vector<int>> commands1 = { {2, 5, 3},{4, 4, 1},{1, 7, 3} };
    
    vector<int> a1 = solution(array1, commands1);

    for (int a : a1) {
        cout << a << " ";
    }
}

