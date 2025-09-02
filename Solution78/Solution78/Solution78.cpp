#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> fvec(100001, -1);

int fibo(int n2) {
    if (fvec[0] == -1) {
        fvec[0] = 0;
        fvec[1] = 1;
    }
    if (fvec[n2] == -1) {
        fvec[n2] = (fibo(n2 - 1) + fibo(n2 - 2)) % 1234567;
    }
    return fvec[n2];
}

int solution(int n) {
    int answer = fibo(n);
    return answer;
}

int main()
{
    cout << solution(3) << endl;
    cout << solution(5) << endl;
}

