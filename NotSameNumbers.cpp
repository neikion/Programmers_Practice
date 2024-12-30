//https://school.programmers.co.kr/learn/courses/30/lessons/12906

#include <vector>

namespace NotSameNumbers {
    using namespace std;

    vector<int> solution(vector<int> arr)
    {
        vector<int> answer;
        answer.push_back(arr[0]);
        for (int i = 1; i < arr.size(); i++) {
            if (answer[answer.size() - 1] != arr[i]) {
                answer.push_back(arr[i]);
            }
        }
        return answer;
    }
}
