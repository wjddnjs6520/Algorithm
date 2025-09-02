#include <iostream>
#include <string>
#include <vector>

using namespace std;


vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> karr;

    for (int i = 0; i < score.size(); i++) {
        bool inserted = false;
        if (karr.empty()) {
            karr.push_back(score[i]);
        }
        else {
            for (int j = 0; j < karr.size(); j++) {
                if (score[i] >= karr[j]) {
                    karr.insert(karr.begin() + j, score[i]);
                    inserted = true;
                    break;
                }
            }
            if (!inserted) {
                karr.push_back(score[i]);
            }
        }  
        if (karr.size() > k) {
            karr.pop_back();
        }
        answer.push_back(karr.back());
    }
    return answer;
}

int main()
{
    vector<int> v1 = { 10, 100, 20, 150, 1, 100, 200 };
    vector<int> a1 = solution(3, v1);
    vector<int> v2 = {0, 300, 40, 300, 20, 70, 150, 50, 500, 1000};
    vector<int> a2 = solution(4, v2);
    
    for (int a : a1) {
        cout << a << " ";
    }
    cout << endl;
    for (int a : a2) {
        cout << a << " ";
    }

}
