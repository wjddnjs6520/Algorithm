#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int rotaterc(vector<vector<int>>& rc, vector<int> query)
{
    int minr = query[0] - 1;
    int minc = query[1] - 1;
    int maxr = query[2] - 1;
    int maxc = query[3] - 1;

    int cr = minr;
    int cc = minc;

    int minnum = rc[cr][cc];
    int tempnum = minnum;
    int idx = 0;

    while (idx < 4)
    {
        minnum = min(minnum, tempnum);

        if (idx == 0) // 오른쪽
        {
            if (cc + 1 <= maxc)
            {
                int tempnum2 = rc[cr][cc + 1];
                rc[cr][cc + 1] = tempnum;
                tempnum = tempnum2;
                cc++;
            }
            else idx++;
        }
        else if (idx == 1) // 아래
        {
            if (cr + 1 <= maxr)
            {
                int tempnum2 = rc[cr + 1][cc];
                rc[cr + 1][cc] = tempnum;
                tempnum = tempnum2;
                cr++;
            }
            else idx++;
        }
        else if (idx == 2) // 왼쪽
        {
            if (cc - 1 >= minc)
            {
                int tempnum2 = rc[cr][cc - 1];
                rc[cr][cc - 1] = tempnum;
                tempnum = tempnum2;
                cc--;
            }
            else idx++;
        }
        else if (idx == 3) // 위
        {
            if (cr - 1 >= minr)
            {
                int tempnum2 = rc[cr - 1][cc];
                rc[cr - 1][cc] = tempnum;
                tempnum = tempnum2;
                cr--;
            }
            else idx++;
        }
    }

    return minnum;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> rc(rows, vector<int>(columns, 0));

    int num = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            rc[i][j] = num++;
        }
    }

    for (auto& q : queries)
    {
        answer.push_back(rotaterc(rc, q));
    }

    return answer;
}

int main() {
    // 테스트 1
    {
        int rows = 6, columns = 6;
        vector<vector<int>> queries = { {2,2,5,4},{3,3,6,6},{5,1,6,3} };
        vector<int> ans = solution(rows, columns, queries);
        for (int x : ans) cout << x << " ";
        cout << endl;
    }

    // 테스트 2
    {
        int rows = 3, columns = 3;
        vector<vector<int>> queries = { {1,1,2,2},{1,2,2,3},{2,1,3,2},{2,2,3,3} };
        vector<int> ans = solution(rows, columns, queries);
        for (int x : ans) cout << x << " ";
        cout << endl;
    }

    // 테스트 3
    {
        int rows = 100, columns = 97;
        vector<vector<int>> queries = { {1,1,100,97} };
        vector<int> ans = solution(rows, columns, queries);
        for (int x : ans) cout << x << " ";
        cout << endl;
    }

    return 0;
}
