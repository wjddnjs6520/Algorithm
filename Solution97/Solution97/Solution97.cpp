#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string word) {
    vector<char> vowels = { 'A','E','I','O','U' };
    vector<int> weight = { 781, 156, 31, 6, 1 }; // 자리별 가중치
    int answer = 0;

    for (int i = 0; i < word.size(); i++) {
        int idx = 0;
        for (int j = 0; j < vowels.size(); j++) {
            if (word[i] == vowels[j]) {
                idx = j;
                break;
            }
        }
        answer += idx * weight[i] + 1;
    }
    return answer;
}

int main() {
    cout << solution("AAAAE") << endl;
    cout << solution("AAAE") << endl;
    cout << solution("I") << endl;    
    cout << solution("EIO") << endl;
}
