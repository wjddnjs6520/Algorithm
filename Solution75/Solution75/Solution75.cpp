#include <iostream>
#include <string>
#include <vector>
#include <sstream>


using namespace std;

string solution(string s) {
    stringstream ss(s);
    int num;
    ss >> num;
    int maxValue = num;
    int minValue = num;

    while (ss >> num) {
        if (num > maxValue) maxValue = num;
        if (num < minValue) minValue = num;
    }

    return to_string(minValue) + " " + to_string(maxValue);
}

int main()
{
    cout << solution("1 2 3 4")<<endl;
    cout << solution("-1 -2 -3 -4") << endl;
    cout << solution("-1 -1") << endl;
}

