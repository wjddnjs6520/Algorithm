#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

bool sosu(long long num) {
    if (num <= 1) return false;
    for (long long i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

string convertToBaseK(int n, int k) {
    string result;
    while (n > 0) {
        result = to_string(n % k) + result;
        n /= k;
    }
    return result;
}

int solution(int n, int k) {
    int answer = 0;

    string baseK = convertToBaseK(n, k);
    stringstream ss(baseK);
    string temp;


    while (getline(ss, temp, '0')) {
        if (temp.empty()) continue;
        long long number = stoll(temp);
        if (sosu(number)) answer++;
    }
    return answer;
}


int main()
{
    std::cout << solution(437674, 3) << endl;
    std::cout << solution(110011, 10) << endl;
}
