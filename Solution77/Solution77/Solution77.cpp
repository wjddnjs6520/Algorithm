#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string toBinary(int num) {
    string result = "";

    if (num == 0) return "0";

    while (num > 0) {
        result += (num % 2) + '0';
        num /= 2;
    }

    reverse(result.begin(), result.end());
    return result;
}

vector<int> solution(string s) {
    vector<int> answer;
    int znum = 0;
    int bnum = 0;
    while (s != "1") {
        string stemp = "";
        for (char c : s) {
            if (c == '1') {
                stemp += c;
            }
            else {
                znum++;
            }
        }
        s = toBinary(stemp.size());
        bnum++;
    }

    answer.push_back(bnum);
    answer.push_back(znum);

    return answer;
}

int main()
{
    vector<int> a1 = solution("110010101001");
    vector<int> a2 = solution("01110");
    vector<int> a3 = solution("1111111");
    for (int a : a1) {
        cout << a << " ";
    }
    cout << endl;
    for (int a : a2) {
        cout << a << " ";
    }
    cout << endl;
    for (int a : a3) {
        cout << a << " ";
    }
    cout << endl;
}
