#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int bapo = 0;
    int fnum = 0;

    for (int i = 0; i < progresses.size(); i++) {
        bapo = 0;
        fnum = 0;

        while (progresses[i] < 100) {
            progresses[i] += speeds[i];
            fnum++;
        }
        for (int j = i; j < progresses.size(); j++) {
            if (progresses[j] + (speeds[j] * fnum) >= 100) {
                bapo++;
            }
            else {
                break;
            }
            
        }

        answer.push_back(bapo);
        i += bapo - 1;
    }


    return answer;
}

int main()
{
    vector<int> p1 = { 93, 30, 55 };
    vector<int> s1 = { 1, 30, 5 };
    vector<int> a1 = solution(p1, s1);

    for (int a : a1) {
        cout << a << " ";
    }
    cout << endl;


    vector<int> p2 = { 95, 90, 99, 99, 80, 99 };
    vector<int> s2 = { 1, 1, 1, 1, 1, 1 };
    vector<int> a2 = solution(p2, s2);

    for (int a : a2) {
        cout << a << " ";
    }
    cout << endl;
}
