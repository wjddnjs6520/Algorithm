#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;

    for (int i = 0; i <= t.size() - p.size(); i++) {
        string temp = "";
        for (int j = i; j < i + p.size(); j++) {
            temp += t[j];
        }
        if (temp <= p) {
            answer++;
        }

    }
    return answer;
}
int main()
{
    string t1 = "3141592";
    string t2 = "500220839878";
    string t3 = "10203";

    string p1 = "271";
    string p2 = "7";
    string p3 = "15";

    cout << solution(t1, p1)<<endl;
    cout << solution(t2, p2) << endl;
    cout << solution(t3, p3) << endl;
}

