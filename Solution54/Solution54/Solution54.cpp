#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    int day = b;
    while (a > 1) {
        switch (a - 1) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            day += 31;
            a--;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            day += 30;
            a--;
            break;
        case 2:
            day += 29;
            a--;
            break;
        }
    }

    switch (day % 7) {
    case 1:
        answer = "FRI";
        break;
    case 2:
        answer = "SAT";
        break;
    case 3:
        answer = "SUN";
        break;
    case 4:
        answer = "MON";
        break;
    case 5:
        answer = "TUE";
        break;
    case 6:
        answer = "WED";
        break;
    case 0:
        answer = "THU";
        break;
    }

    return answer;
}

int main()
{
    cout << solution(5, 24);
}
