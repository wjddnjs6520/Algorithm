#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    // 벡터와 맵 데이터 정의
    vector<int> vec = { 10, 20, 30, 40, 50 };
    map<string, int> mp = {
        {"Alice", 90},
        {"Bob", 85},
        {"Charlie", 95}
    };

    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    for (map<string, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
        cout << it->first << " : " << it->second << " ";
    }

    for (vector<int>::const_reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it) {
        cout << *it << " "; 
    }
    cout << endl;

    for (map<string, int>::const_reverse_iterator it = mp.rbegin(); it != mp.rend(); ++it) {
        cout << it->first << " : " << it->second << " ";
    }
    

    return 0;
}
