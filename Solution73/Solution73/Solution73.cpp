#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int h = park.size();
    int w = park[0].size();

    for (int i = 0; i < h; i++) {
        for (int r = 0; r < w; r++) {
            if (park[i][r] == 'S') {
                answer.push_back(i);
                answer.push_back(r);
                break;
            }
        }
    }


    for (int j = 0; j < routes.size(); j++) {
        char rc = routes[j][0];
        int md = stoi(routes[j].substr(2));
        bool bgo = true;

        if (rc == 'E') {
            //거리 초과 시 안감.
            if (answer[1] + md >= w) {
                continue;
            }
            for (int k = 1; k <= md; k++) {
                if (park[answer[0]][answer[1] + k] == 'X') {
                    bgo = false;
                    break;
                }
            }
            if (bgo) answer[1] += md;
        }
        if (rc == 'W') {
            //거리 초과 시 안감.
            if (answer[1] - md < 0) {
                continue;
            }
            for (int k = 1; k <= md; k++) {
                if (park[answer[0]][answer[1] - k] == 'X') {
                    bgo = false;
                    break;
                }
            }
            if (bgo) answer[1] -= md;
        }

        if (rc == 'S') {
            if (answer[0] + md >= h) {
                continue;
            }
            for (int k = 1; k <= md; k++) {
                if (park[answer[0] + k][answer[1]] == 'X') {
                    bgo = false;
                    break;
                }
            }

            if (bgo) {
                answer[0] = answer[0] + md;
            }
        }
        if (rc == 'N') {
            if (answer[0] - md < 0) {
                continue;
            }
            for (int k = 1; k <= md; k++) {
                if (park[answer[0] - k][answer[1]] == 'X') {
                    bgo = false;
                    break;
                }
            }

            if (bgo) {
                answer[0] = answer[0] - md;
            }
        }
    }


    return answer;
}
int main() {
    vector<string> park1 = { "SOO","OOO","OOO" };
    vector<string> routes1 = { "E 2","S 2","W 1" };
    vector<int> result1 = solution(park1, routes1);
    cout << "result1: [" << result1[0] << ", " << result1[1] << "]" << endl;

    vector<string> park2 = { "SOO","OXX","OOO" };
    vector<string> routes2 = { "E 2","S 2","W 1" };
    vector<int> result2 = solution(park2, routes2);
    cout << "result2: [" << result2[0] << ", " << result2[1] << "]" << endl;

    vector<string> park3 = { "OSO","OOO","OXO","OOO" };
    vector<string> routes3 = { "E 2","S 3","W 1" };
    vector<int> result3 = solution(park3, routes3);
    cout << "result3: [" << result3[0] << ", " << result3[1] << "]" << endl;

    return 0;
}

