#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    unordered_map<char, int> smap;

    for (int i = 0; i < s.size(); i++)
    {
        auto it = smap.find(s[i]);
        if (it != smap.end())
        {
            answer.push_back(i - it->second);
            it->second = i;
        }
        else
        {
            answer.push_back(-1);
            smap[s[i]] = i;
        }
    }
    return answer;
}
int main()
{
    vector<int> a1 = solution("banana");
    vector<int> a2 = solution("foobar");


    for (int a : a1)
    {
        cout << a << " ";
    }
    cout << '\n';
    for (int a : a2)
    {
        cout << a << " ";
    }
    cout << '\n';
}

