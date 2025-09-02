#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> numbers) {
    int n = numbers.size();
    vector<int> answer(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && numbers[st.top()] < numbers[i]) {
            answer[st.top()] = numbers[i];
            st.pop();
        }
        st.push(i);
    }

    return answer;
}

int main()
{
    vector<int> n1 = { 2, 3, 3, 5 };
    vector<int> n2 = { 9, 1, 5, 3, 6, 2 };

    vector<int> a1 = solution(n1);
    vector<int> a2 = solution(n2);

    for (int a : a1)
    {
        cout << a << " ";
    }
    cout << endl;

    for (int a : a2)
    {
        cout << a << " ";
    }
    cout << endl;
}
