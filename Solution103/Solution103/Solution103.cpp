#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const string& a, const string& b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    vector<string> strNums;
    for (int num : numbers)
        strNums.push_back(to_string(num));

    sort(strNums.begin(), strNums.end(), compare);

    string answer;
    for (auto& s : strNums)
        answer += s;

    if (answer[0] == '0')
        return "0";

    return answer;
}

int main() {
    vector<int> numbers1 = { 6, 10, 2 };
    vector<int> numbers2 = { 3, 30, 34, 5, 9 };

    cout << "Input: [6, 10, 2] -> " << solution(numbers1) << endl;
    cout << "Input: [3, 30, 34, 5, 9] -> " << solution(numbers2) << endl;

    return 0;
}
