#include <iostream>
#include <vector>
using namespace std;

vector<int> answer(2, 0);

void abchu(const vector<vector<int>>& arr, int x, int y, int size)
{
    int num = arr[x][y];
    bool same = true;

    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            if (num != arr[i][j])
            {
                same = false;
                break;
            }
        }
        if (!same) break;
    }

    if (same)
    {
        answer[num]++;
        return;
    }

    int half = size / 2;
    abchu(arr, x, y, half);
    abchu(arr, x, y + half, half);
    abchu(arr, x + half, y, half);
    abchu(arr, x + half, y + half, half);
}

vector<int> solution(vector<vector<int>> arr) {
    answer = { 0,0 };
    int n = arr.size();
    abchu(arr, 0, 0, n);
    return answer;
}


int main() {
    vector<vector<int>> arr1 = {
        {1,1,0,0},
        {1,0,0,0},
        {1,0,0,1},
        {1,1,1,1}
    };

    vector<vector<int>> arr2 = {
        {1,1,1,1,1,1,1,1},
        {0,1,1,1,1,1,1,1},
        {0,0,0,0,1,1,1,1},
        {0,1,0,0,1,1,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,0,1},
        {0,0,0,0,1,0,0,1},
        {0,0,0,0,1,1,1,1}
    };

    vector<int> result1 = solution(arr1);
    cout << "[" << result1[0] << ", " << result1[1] << "]" << endl;

    vector<int> result2 = solution(arr2);
    cout << "[" << result2[0] << ", " << result2[1] << "]" << endl;

    return 0;
}
