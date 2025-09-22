#include <iostream>

using namespace std;

long long mygcd(long long a, long long b) {
    while (b != 0) {
        long long tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

long long solution(int w, int h) {
    long long longw = w;
    long long longh = h;

    long long g = mygcd(longw, longh);

    long long minw = longw / g;
    long long minh = longh / g;

    long long p = minw + minh - 1;

    long long answer = longw * longh - (p * g);

    return answer;
}

int main() {
    int w = 8, h = 12;
    cout << solution(w, h) << endl; // 예상 결과: 80
    return 0;
}
