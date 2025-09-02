#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> temp;
    while (n > 10) {
        temp.push_back(n % 10);
        n = n / 10;
    }
    temp.push_back(n % 10);
    int tempnumbers;
    for (int i = 0; i < temp.size(); i++) {
        tempnumbers = temp[i];
        for (int j = i + 1; j < temp.size(); j++) {
            if (temp[i] > temp[j]) {//i 번째가 j 번째보다 크면 서로 교체
                tempnumbers = temp[i];
                temp[i] = temp[j];
                temp[j] = tempnumbers;
            }
        }

    }
    int b = 1;
    for (int i = 0; i < temp.size(); i++) {
        answer += temp[i] * b;
        b *= 10;
    }
    return answer;
}

int main()
{
    cout << solution(118372);
}
