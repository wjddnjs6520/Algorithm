#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int wmax = 0;
    int hmax = 0;
    for (int i = 0; i < sizes.size(); i++) {
        if (sizes[i][0] < sizes[i][1]) {
            if (wmax < sizes[i][1]) {
                wmax = sizes[i][1];
            }
            if (hmax < sizes[i][0]) {
                hmax = sizes[i][0];
            }
        }
        else {
            if (wmax < sizes[i][0]) {
                wmax = sizes[i][0];
            }
            if (hmax < sizes[i][1]) {
                hmax = sizes[i][1];
            }
        }
    }
    answer = wmax * hmax;
    return answer;
}

int main()
{
    vector<vector<int>> v1 = { {60, 50},{30, 70},{60, 30},{80, 40} };
    vector<vector<int>> v2 = { {10, 7},{12, 3},{8, 15},{14, 7}, {5, 15} };
    vector<vector<int>> v3 = { {14, 4},{19, 6},{6, 16},{18, 7}, {7, 11} };

    std::cout << solution(v1)<<endl;
    std::cout << solution(v2) << endl;
    std::cout << solution(v3) << endl;
}

