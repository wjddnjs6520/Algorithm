#include <iostream>
#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    double answer = 0;
    for (int n : numbers) {
        answer += n;
    }
    answer /= numbers.size();
    return answer;
}
int main()
{
    std::vector<int> numbers1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> numbers2 = { 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99};
    std::cout << solution(numbers1) << std::endl;
    std::cout << solution(numbers2) << std::endl;
}
