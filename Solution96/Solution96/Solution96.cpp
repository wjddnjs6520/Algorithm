#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>


using namespace std;

int timeToMinute(const string& time) {
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    return h * 60 + m;
}

int calculateFee(int totalTime, const vector<int>& fees) {
    int baseTime = fees[0], baseFee = fees[1];
    int unitTime = fees[2], unitFee = fees[3];

    if (totalTime <= baseTime) return baseFee;

    return baseFee + ceil((totalTime - baseTime) / (double)unitTime) * unitFee;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    map<string, int> inTime;
    map<string, int> totalTime;

    for (const auto& record : records) {
        stringstream ss(record);
        string timeStr, car, type;
        ss >> timeStr >> car >> type;

        int minute = timeToMinute(timeStr);

        if (type == "IN") {
            inTime[car] = minute;
        }
        else {
            totalTime[car] += (minute - inTime[car]);
            inTime.erase(car);
        }
    }

    for (const auto& p : inTime) {
        totalTime[p.first] += (1439 - p.second);
    }

    vector<int> answer;
    for (const auto& p : totalTime) {
        answer.push_back(calculateFee(p.second, fees));
    }

    return answer;
}

int main()
{
    vector<int> f1 = { 180, 5000, 10, 600 };
    vector<int> f2 = { 120, 0, 60, 591 };
    vector<int> f3 = { 1, 461, 1, 10 };
    vector<string> r1 = { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" };
    vector<string> r2 = { "16:00 3961 IN","16:00 0202 IN","18:00 3961 OUT","18:00 0202 OUT","23:58 3961 IN" };
    vector<string> r3 = { "00:00 1234 IN" };
    vector<int> a1 = solution(f1,r1);
    vector<int> a2 = solution(f2,r2);
    vector<int> a3 = solution(f3,r3);
    

    for (int a : a1) {
        cout << a << " ";
    }
    cout << endl;

    for (int a : a2) {
        cout << a << " ";
    }
    cout << endl;

    for (int a : a3) {
        cout << a << " ";
    }
    cout << endl;
}
