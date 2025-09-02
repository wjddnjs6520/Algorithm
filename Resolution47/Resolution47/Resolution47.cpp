#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    sort(strings.begin(), strings.end(), [n](const string& a, const string& b) {
        if (a[n] == b[n]) return a < b;
        return a[n] < b[n];
        });
    return strings;
}

int main()
{
    vector<string> s1 = { "sun", "bed", "car" };
    vector<string> s2 = { "abce", "abcd", "cdx" };

    vector<string> a1 = solution(s1, 1);
    vector<string> a2 = solution(s2, 2);

    for (string a : a1) {
        cout << a << " ";
    }
    cout << endl;
    for (string a : a2) {
        cout << a << " ";
    }
}
