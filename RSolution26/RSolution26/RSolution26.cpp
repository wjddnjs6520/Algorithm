#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;

    for (int i = 0; i < absolutes.size(); i++) {
        if (signs[i]) {
            answer += absolutes[i];
        }
        else {
            answer -= absolutes[i];
        }
    }
    return answer;
}

int main()
{
    vector<int> a1 = { 4,7,12 };
    vector<bool> s1 = { true, false, true };
    vector<int> a2 = { 1,2,3 };
    vector<bool> s2 = { false,false,true };
    cout << solution(a1, s1) << endl;
    cout << solution(a2, s2);
}


