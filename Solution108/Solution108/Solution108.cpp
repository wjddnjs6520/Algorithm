#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> dal(n);
    for (int i = 0; i < n; i++)
    {
        dal[i].resize(i + 1, 0);
    }

    int num = 1;
    int x = -1;
    int y = 0;
    int go = 0;

    int total = n * (n + 1) / 2;

    for (int j = 0; j < total; j++)
    {
        if (go == 0)
        {
            x++;
        }
        else if (go == 1)
        {
            y++;
        }
        else if (go == 2)
        {
            x--;
            y--;
        }

        dal[x][y] = num;
        num++;

        if (go == 0)
        {
            if (x + 1 == n || dal[x + 1][y] != 0) go = 1;
        }
        else if (go == 1)
        {
            if (y + 1 == dal[x].size() || dal[x][y + 1] != 0) go = 2;
        }
        else if (go == 2)
        {
            if (x - 1 < 0 || y - 1 < 0 || dal[x - 1][y - 1] != 0) go = 0;
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int l = 0; l <= k; l++)
        {
            answer.push_back(dal[k][l]);
        }
    }

    return answer;
}

int main() {
    vector<int> result;

    for (int n : {4, 5, 6}) {
        result = solution(n);
        cout << "n = " << n << " 결과: ";
        for (int val : result) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}
