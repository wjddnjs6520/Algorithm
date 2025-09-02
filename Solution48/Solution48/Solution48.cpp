#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    vector<int> arr;
    for (int i = 0; i < nums.size() - 2; i++) {
        for (int j = i + 1; j < nums.size() - 1; j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                int a = nums[i] + nums[j] + nums[k];
                for (int x = 2; x <= a; x++) {
                    if (x == a) {
                        answer++;
                        arr.push_back(a);
                    }
                    if (a % x == 0) {
                        break;
                    }
                }
            }

        }
    }
    return answer;
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 4};
    vector<int> arr2 = { 1, 2, 7, 6, 4 };
    cout << solution(arr1) << endl;
    cout << solution(arr2) << endl;
}
