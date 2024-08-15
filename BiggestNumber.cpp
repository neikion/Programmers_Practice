//https://school.programmers.co.kr/learn/courses/30/lessons/42746

#include <string>
#include <vector>
#include <algorithm>

namespace BiggestNumber {
    using namespace std;

    string solution(vector<int> numbers) {
        string answer = "";

        sort(numbers.begin(), numbers.end(), [](int v1, int v2)->bool {
            auto value1 = to_string(v1);
            auto value2 = to_string(v2);
            return atoi((value1 + value2).c_str()) > atoi((value2 + value1).c_str());
        });
        for (int i = 0; i < numbers.size(); i++) {
            answer += to_string(numbers[i]);
        }
        if (atoi(answer.c_str()) == 0) {
            return "0";
        }
        return answer;
    }
}