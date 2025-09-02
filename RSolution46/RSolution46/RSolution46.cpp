#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string s) {
    int answer = 0;
    unordered_map<string, string> smap = {
        {"zero", "0"}, {"one", "1"}, {"two", "2"}, {"three", "3"}, {"four", "4"},
        {"five", "5"}, {"six", "6"}, {"seven", "7"}, {"eight", "8"}, {"nine", "9"}
    };

    string sanswer;
    string temp;

    for (char c : s) {
        if (c >= '0' && c <= '9') {
            sanswer += c;
        }
        else {
            temp += c;
            if (smap.find(temp) != smap.end()) {
                sanswer += smap[temp];
                temp.clear();
            }
        }
    }

    answer = stoi(sanswer);

    return answer;
}

int main()
{
    cout << solution("one4seveneight")<<endl;
    cout << solution("23four5six7") << endl;
    cout << solution("2three45sixseven") << endl;
    cout << solution("123") << endl;
    
}

