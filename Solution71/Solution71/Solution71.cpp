#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 날짜를 일수로 변환하는 함수 (1년 12달, 1달 28일)
int cday(string today, string pri) {
    int td = stoi(today.substr(0, 4)) * 336 + (stoi(today.substr(5, 2)) - 1) * 28 + stoi(today.substr(8, 2));
    int pd = stoi(pri.substr(0, 4)) * 336 + (stoi(pri.substr(5, 2)) - 1) * 28 + stoi(pri.substr(8, 2));
    return td - pd;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    for (int i = 0; i < privacies.size(); i++) {
        int ds = cday(today, privacies[i]);

        char type = privacies[i][privacies[i].size() - 1];
        int term_days = 0;

        for (int j = 0; j < terms.size(); j++) {
            if (terms[j][0] == type) {
                term_days = stoi(terms[j].substr(2)) * 28;
                break;
            }
        }

        if (ds >= term_days) {
            answer.push_back(i + 1);
        }
    }

    return answer;
}

int main() {
    // 예제 1
    string today1 = "2022.05.19";
    vector<string> terms1 = { "A 6", "B 12", "C 3" };
    vector<string> privacies1 = { "2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C" };

    vector<int> result1 = solution(today1, terms1, privacies1);

    cout << "예제 1 결과: ";
    for (int num : result1) cout << num << " ";
    cout << endl;

    // 예제 2
    string today2 = "2020.01.01";
    vector<string> terms2 = { "Z 3", "D 5" };
    vector<string> privacies2 = { "2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z" };

    vector<int> result2 = solution(today2, terms2, privacies2);

    cout << "예제 2 결과: ";
    for (int num : result2) cout << num << " ";
    cout << endl;

    return 0;
}
