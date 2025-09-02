#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    map<string, int> imap;
    map<string, vector<string>> smap;
    set<string> rset(report.begin(), report.end());
    vector<int> answer;

    for (string s : rset) {
        string from = s.substr(0, s.find(' '));
        string to = s.substr(s.find(' ') + 1);
        smap[to].push_back(from);
    }

    for (auto it = smap.begin(); it != smap.end(); ++it) {
        vector<string> froms = it->second;

        if (froms.size() >= k) {
            for (auto from : froms) {
                imap[from]++;
            }
        }
    }


    for (string id : id_list) {
        answer.push_back(imap[id]);
    }


    return answer;
}

void print(vector<int> vec) {
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main() {
    // 첫 번째 테스트 케이스
    vector<string> id_list1 = { "muzi", "frodo", "apeach", "neo" };
    vector<string> report1 = { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" };
    int k1 = 2;
    vector<int> result1 = solution(id_list1, report1, k1);

    cout << "결과 1: ";
    print(result1); // 예상 출력 : 2 1 1 0

    // 두 번째 테스트 케이스
    vector<string> id_list2 = { "con", "ryan" };
    vector<string> report2 = { "ryan con", "ryan con", "ryan con", "ryan con" };
    int k2 = 3;
    vector<int> result2 = solution(id_list2, report2, k2);

    cout << "결과 2: ";
    print(result2); // 예상 출력 : 0 0

    return 0;
}
