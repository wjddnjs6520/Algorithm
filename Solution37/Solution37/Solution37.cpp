#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(), vector<int>(arr1[0].size(), 0));
    for (int i = 0; i < arr1.size(); i++) {
        for (int j = 0; j < arr1[0].size(); j++) {
            answer[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    return answer;
}

int main() {
    // 2x2 행렬
    vector<vector<int>> arr1(2, vector<int>(2, 0));
    vector<vector<int>> arr2(2, vector<int>(2, 0));

    arr1[0][0] = 1;
    arr1[0][1] = 2;
    arr1[1][0] = 2;
    arr1[1][1] = 3;

    arr2[0][0] = 3;
    arr2[0][1] = 4;
    arr2[1][0] = 5;
    arr2[1][1] = 6;

    // 1x2 행렬로 수정
    vector<vector<int>> arr3(1, vector<int>(2, 0));
    vector<vector<int>> arr4(1, vector<int>(2, 0));

    arr3[0][0] = 1;
    arr3[0][1] = 2;
    arr4[0][0] = 3;
    arr4[0][1] = 4;

    vector<vector<int>> arr5 = solution(arr1, arr2);
    vector<vector<int>> arr6 = solution(arr3, arr4);

    // arr5 출력
    for (int i = 0; i < arr5.size(); i++) {
        for (int j = 0; j < arr5[i].size(); j++) {
            cout << arr5[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    // arr6 출력
    for (int i = 0; i < arr6.size(); i++) {
        for (int j = 0; j < arr6[i].size(); j++) {
            cout << arr6[i][j] << " ";
        }
        cout << endl;
    }
}
