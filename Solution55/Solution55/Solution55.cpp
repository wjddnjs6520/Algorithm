#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    bool test = true;
    int i = 0;
    int j = 0;
    int k = 0;
    while (k < goal.size()) {
        if (cards1[i] != goal[k]) {
            if (cards2[j] != goal[k]) {
                test = false;
                break;
            }
            else {
                j++;
                k++;
                continue;
            }
        }
        else {
            i++;
            k++;
            continue;
        }
    }

    if (test) {
        answer = "Yes";
    }
    else {
        answer = "No";
    }
    return answer;
}

int main()
{
    vector<string> card11 = { "i", "drink", "water" };
    vector<string> card12 = { "i", "water", "drink" };
    vector<string> card21 = { "want", "to" };
    vector<string> card22 = { "want", "to" };
    vector<string> goal1 = { "i", "want", "to", "drink", "water" };
    vector<string> goal2 = { "i", "want", "to", "drink", "water" };
    cout << solution(card11, card21, goal1) << endl;
    cout << solution(card12, card22, goal2);
}