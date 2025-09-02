#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    set<int> eset;
    vector<int> extended(elements);
    extended.insert(extended.end(), elements.begin(), elements.end());

    for (int i = 1; i <= elements.size(); i++) {
        for (int j = 0; j < elements.size(); j++) {
            int sum = 0;
            for (int k = 0; k < i; k++) {
                sum += extended[j + k];
            }
            eset.insert(sum);
        }
    }

    answer = eset.size();
    return answer;
}

int main()
{
    vector<int> e1 = { 7, 9, 1, 1, 4 };
    cout << solution(e1);
}