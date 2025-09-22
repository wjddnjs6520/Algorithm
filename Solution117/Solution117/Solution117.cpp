#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;

    while (storey > 0)
    {
        int currentint = storey % 10;

        if (currentint > 5)
        {
            answer += (10 - currentint);
            storey = storey / 10 + 1;
        }
        else if (currentint < 5)
        {
            answer += currentint;
            storey = storey / 10;
        }
        else
        {
            int nextint = (storey / 10) % 10;
            if (nextint >= 5)
            {
                answer += (10 - currentint);
                storey = storey / 10 + 1;
            }
            else
            {
                answer += currentint;
                storey = storey / 10;
            }
        }
    }


    return answer;
}

int main() {
    vector<int> testCases = { 16, 2554 };
    for (int storey : testCases) {
        cout << "storey = " << storey
            << " → result = " << solution(storey) << endl;
    }
    return 0;
}