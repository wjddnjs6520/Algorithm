#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> tanmap;


    for (int i = 0; i < tangerine.size(); ++i) {
        tanmap[tangerine[i]]++;
    }


    vector<pair<int, int>> v(tanmap.begin(), tanmap.end());


    sort(v.begin(), v.end(), [](auto& a, auto& b) {
        return a.second > b.second;
        });

    for (int i = 0; i < v.size(); ++i) {
        k -= v[i].second;
        answer = i + 1;
        if (k <= 0) break;
    }

    return answer;
}

int main()
{
    vector<int> t1 = { 1,3,2,5,4,5,2,3 };
    vector<int> t2 = { 1, 3, 2, 5, 4, 5, 2, 3 };
    vector<int> t3 = { 1, 1, 1, 1, 2, 2, 2, 3 };


    cout << solution(6, t1) << endl;
    cout << solution(4, t2) << endl;
    cout << solution(2, t3) << endl;
}

