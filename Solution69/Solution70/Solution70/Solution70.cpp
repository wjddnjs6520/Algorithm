#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer(4);
    bool fc = true;
    for (int i = 0; i < wallpaper.size(); i++) {
        for (int j = 0; j < wallpaper[i].size(); j++) {
            if (wallpaper[i][j] == '#') {
                if (fc) {
                    answer[0] = i;
                    answer[1] = j;
                    answer[2] = i + 1;
                    answer[3] = j + 1;
                    fc = false;
                }
                else {
                    if (answer[0] > i) {
                        answer[0] = i;
                    }
                    if (answer[1] > j) {
                        answer[1] = j;
                    }
                    if (answer[2] < i + 1) {
                        answer[2] = i + 1;
                    }
                    if (answer[3] < j + 1) {
                        answer[3] = j + 1;
                    }
                }

            }
        }
    }
    return answer;
}

int main()
{
    vector<string> w1 = { ".#...", "..#..", "...#." };
    vector<string> w2 = { "..........", ".....#....", "......##..", "...##.....", "....#....." };
    vector<string> w3 = { ".##...##.", "#..#.#..#", "#...#...#", ".#.....#.", "..#...#..", "...#.#...", "....#...." };
    vector<string> w4 = { "..", "#." };

    vector<int> a1 = solution(w1);
    vector<int> a2 = solution(w2);
    vector<int> a3 = solution(w3);
    vector<int> a4 = solution(w4);

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
    for (int a : a4) {
        cout << a << " ";
    }
    cout << endl;
}   

