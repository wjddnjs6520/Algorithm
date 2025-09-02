#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int cnum = 0;
    int znum = 0;

    for (int a = 0; a < lottos.size(); a++) {
        auto it = find(win_nums.begin(), win_nums.end(), lottos[a]);
        if (it != win_nums.end()) {
            cnum++;
        }
        else if (lottos[a] == 0) {
            znum++;
        }
    }
    if (cnum + znum <= 1) {
        answer.push_back(6);
    }
    else {
        answer.push_back(7 - cnum - znum);
    }
    if (cnum == 0) {
        answer.push_back(6);
    }
    else {
        answer.push_back(7 - cnum);
    }

    

    return answer;
}
int main()
{
    vector<int> l1 = { 44, 1, 0, 0, 31, 25 };
    vector<int> l2 = { 0, 0, 0, 0, 0, 0 };
    vector<int> l3 = { 45, 4, 35, 20, 3, 9 };
    vector<int> w1 = { 31, 10, 45, 1, 6, 19 };
    vector<int> w2 = { 38, 19, 20, 40, 15, 25 };
    vector<int> w3 = { 20, 9, 3, 45, 4, 35 };

    vector<int> r1 = solution(l1, w1);
    vector<int> r2 = solution(l2, w2);
    vector<int> r3 = solution(l3, w3);

    for (int i : r1) {
        cout << i << " ";
    }
    cout << endl;
    for (int i : r2) {
        cout << i << " ";
    }
    cout << endl; 
    for (int i : r3) {
        cout << i << " ";
    }
    cout << endl;
}
