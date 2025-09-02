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
            answer += (-1) * absolutes[i];
        }
    }
    return answer;
}

int main()
{
    vector<int> absolutes1 = { 4, 7, 12 };
    vector<int> absolutes2 = { 1, 2, 3 };
    vector<bool> signs1 = { true, false, true };
    vector<bool> signs2 = { false, false, true };
    std::cout << solution(absolutes1, signs1)<<endl;
    std::cout << solution(absolutes2, signs2);
}
