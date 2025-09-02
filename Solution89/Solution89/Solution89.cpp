#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> smap;
    bool gabool;

    int nsum = 0;
    for (int a : number) {
        nsum += a;
    }

    for (string s : want) {
        smap[s] = 0;
    }


    for (int i = 0; i < discount.size() - nsum + 1; i++) {
        smap.clear();
        gabool = true;
        for (int j = i; j < i + nsum; j++) {
            smap[discount[j]]++;
        }
        for (int k = 0; k < number.size(); k++) {
            if (smap[want[k]] != number[k]) {
                gabool = false;
                break;
            }
        }

        if (gabool) {
            answer++;
        }
    }

    return answer;
}

int main()
{
    vector<string> w1 = { "banana", "apple", "rice", "pork", "pot" };
    vector<int> n1 = { 3, 2, 2, 2, 1 };
    vector<string> d1 = { "chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana" };
    std::cout << solution(w1, n1, d1) << endl;

    vector<string> w2 = { "apple" };
    vector<int> n2 = { 10 };
    vector<string> d2 = { "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana" };
    std::cout << solution(w2, n2, d2) << endl;

}

