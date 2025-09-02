#include <iostream>
#include <string>
#include <vector>

using namespace std;

int answer;

void findtarget(const vector<int>& numbers, const int target, int index, int sum)
{
    if (index == numbers.size())
    {
        if (sum == target)
        {
            answer++;
        }
        return;
    }

    findtarget(numbers, target, index + 1, sum + numbers[index]);
    findtarget(numbers, target, index + 1, sum - numbers[index]);
}


int solution(vector<int> numbers, int target) {
    answer = 0;
    findtarget(numbers, target, 0, 0);
    return answer;
}
int main()
{
    vector<int> n1 = { 1, 1, 1, 1, 1 };
    vector<int> n2 = { 4, 1, 2, 1 };

    cout << solution(n1, 3) << endl;
    cout << solution(n2, 4) << endl;
}