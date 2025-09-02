#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> cnum;

    for (int i = 0; i < clothes.size(); i++) {
        cnum[clothes[i][1]]++;
    }

    for (auto it = cnum.begin(); it != cnum.end(); ++it) {
        answer = answer * (it->second + 1);
    }

    answer--;

    return answer;
}

int main()
{
    vector<vector<string>> c1 = { {"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"} , {"green_turban", "headgear"} };
    vector<vector<string>> c2 = { {"crow_mask", "face"}, {"blue_sunglasses", "face"} , {"smoky_makeup", "face"} };
    std::cout << solution(c1) << endl;
    std::cout << solution(c2) << endl;
}
