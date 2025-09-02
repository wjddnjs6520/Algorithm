#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    vector<int> vector1 = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    for (int a : numbers) {
        vector1[a] = 1;
    }

    for (int b = 0; b < vector1.size(); b++) {
        if (vector1[b] == 0) {
            answer += b;
        }
    }

    return answer;
}

int main()
{
    vector<int> n1 = { 1, 2, 3, 4, 6, 7, 8, 0 };
    vector<int> n2 = { 5, 8, 4, 0, 6, 7, 9 };
    std::cout << solution(n1) << endl;
    std::cout << solution(n2) << endl;
}

