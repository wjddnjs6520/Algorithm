#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> a;
    while (n >= 3) {
        a.push_back(n % 3);
        n = n / 3;
    }
    a.push_back(n);
    for (int i = 0; i < a.size(); i++) {
        cout<< " " << a[i];
    }
    cout << endl;
    for (int i = 0; i < a.size(); i++) {
        answer += a[i] * pow(3, a.size() - i- 1);
    }

    return answer;
}

int main()
{
    std::cout << "answer: " << solution(45) << endl;
    std::cout << "answer: " << solution(125) << endl;

}