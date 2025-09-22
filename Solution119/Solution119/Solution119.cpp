#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int gogbasu(const vector<int>& array)
{
    int g = 0;
    for (int i = 1; i <= array[0]; i++)
    {
        bool cang = true;
        for (int j = 0; j < array.size(); j++)
        {
            if (array[j] % i != 0)
            {
                cang = false;
                break;
            }
        }
        if (cang) g = i;
    }
    return g;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;

    int ga = gogbasu(arrayA);
    int gb = gogbasu(arrayB);

    bool acan = true;
    for (int ab : arrayB)
    {
        if (ab % ga == 0)
        {
            acan = false;
            break;
        }
    }
    if (acan) answer = max(answer, ga);

    bool bcan = true;
    for (int aa : arrayA)
    {
        if (aa % gb == 0)
        {
            bcan = false;
            break;
        }
    }
    if (bcan) answer = max(answer, gb);

    return answer;
}

int main() {
    vector<int> a1 = { 10, 17 };
    vector<int> b1 = { 5, 20 };
    cout << solution(a1, b1) << endl; // 기대값: 0

    vector<int> a2 = { 10, 20 };
    vector<int> b2 = { 5, 17 };
    cout << solution(a2, b2) << endl; // 기대값: 10

    vector<int> a3 = { 14, 35, 119 };
    vector<int> b3 = { 18, 30, 102 };
    cout << solution(a3, b3) << endl; // 기대값: 7

    return 0;
}
