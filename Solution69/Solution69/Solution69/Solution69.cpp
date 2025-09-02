#include <iostream>
#include <string>
#include <vector>

using namespace std;

void vectask(char c, vector<int>& vec, int h) {
    if (c == 'R') {
        vec[0] += h;
    }
    else if (c == 'T') {
        vec[0] -= h;
    }
    else if (c == 'C') {
        vec[1] += h;
    }
    else if (c == 'F') {
        vec[1] -= h;
    }
    else if (c == 'J') {
        vec[2] += h;
    }
    else if (c == 'M') {
        vec[2] -= h;
    }
    else if (c == 'A') {
        vec[3] += h;
    }
    else if (c == 'N') {
        vec[3] -= h;
    }
}



string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    vector<int> avec(4);

    for (int i = 0; i < survey.size(); i++) {
        switch (choices[i]) {
        case 1:
            vectask(survey[i][0], avec, 3);
            break;
        case 2:
            vectask(survey[i][0], avec, 2);
            break;
        case 3:
            vectask(survey[i][0], avec, 1);
            break;
        case 4:
            vectask(survey[i][0], avec, 0);
            break;
        case 5:
            vectask(survey[i][0], avec, -1);
            break;
        case 6:
            vectask(survey[i][0], avec, -2);
            break;
        case 7:
            vectask(survey[i][0], avec, -3);
            break;
        }
    }
    if (avec[0] >= 0) {
        answer += "R";
    }
    else {
        answer += "T";
    }
    if (avec[1] >= 0) {
        answer += "C";
    }
    else {
        answer += "F";
    }
    if (avec[2] >= 0) {
        answer += "J";
    }
    else {
        answer += "M";
    }
    if (avec[3] >= 0) {
        answer += "A";
    }
    else {
        answer += "N";
    }
    return answer;
}

int main()
{
    vector<string> s1 = { "AN", "CF", "MJ", "RT", "NA" };
    vector<int> c1 = { 5, 3, 2, 7, 5 };
    vector<string> s2 = { "TR", "RT", "TR" };
    vector<int> c2 = { 7, 1, 3 };
    std::cout << solution(s1, c1) << endl;
    std::cout << solution(s2, c2) << endl;
}
