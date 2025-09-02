#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

set<int> uniquePrimes;

void dfs(const string& numbers, string current, vector<bool>& used) {
    if (!current.empty())
    {
        int num = stoi(current);

        if (num >= 2)
        {
            bool pri = true;
            int sqrtNum = (int)sqrt(num);
            for (int i = 2; i <= sqrtNum; i++)
            {
                if (num % i == 0)
                {
                    pri = false;
                    break;
                }
            }
            if (pri) uniquePrimes.insert(num);
        }
    }

    for (int i = 0; i < numbers.size(); i++) {
        if (!used[i]) {
            used[i] = true;
            dfs(numbers, current + numbers[i], used);
            used[i] = false;
        }
    }
}

int solution(string numbers) {
    uniquePrimes.clear();
    vector<bool> used(numbers.size(), false);
    dfs(numbers, "", used);
    return uniquePrimes.size();
}

int main() {
    string test1 = "17";
    string test2 = "011";

    cout << solution(test1) << endl;
    cout << solution(test2) << endl;

    return 0;
}
