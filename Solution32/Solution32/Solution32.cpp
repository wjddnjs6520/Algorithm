#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    for (int i = 0; i < a.size(); i++) {
        answer += a[i] * b[i];
    }
    return answer;
}

int main()
{
    vector<int> a1 = { 1,2,3,4 };
    vector<int> a2 = { -1,0,1 };
    vector<int> b1 = { -3,-1,0,2 };
    vector<int> b2 = { 1,0,-1 };
    std::cout << solution(a1, b1) << endl;
    std::cout << solution(a2, b2) << endl;
}

