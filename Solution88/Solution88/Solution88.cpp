#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(), vector<int>(arr2[0].size(), 0));

    for (int i = 0; i < arr1.size(); i++) {
        for (int j = 0; j < arr2[0].size(); j++) {
            int sum = 0;
            for (int k = 0; k < arr1[0].size(); k++) {
                sum += arr1[i][k] * arr2[k][j];
            }
            answer[i][j] = sum;
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> arr11 = { {1,4},{3,2},{4,1} };
    vector<vector<int>> arr21 = { {3, 3} ,{3, 3} };
    vector<vector<int>> arr12 = { {2,3,2},{4,2,4},{3,1,4} };
    vector<vector<int>> arr22 = { {5,4,3},{2,4,1},{3,1,1} };
    vector<vector<int>> a1 = solution(arr11, arr21);
    vector<vector<int>> a2 = solution(arr12, arr22);
    for (int i = 0; i < a1.size(); i++) {
        for (int j = 0; j < a1[0].size(); j++) {
            cout << a1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < a2.size(); i++) {
        for (int j = 0; j < a2[0].size(); j++) {
            cout << a2[i][j] << " ";
        }
        cout << endl;
    }
}
