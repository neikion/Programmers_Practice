//https://school.programmers.co.kr/learn/courses/30/lessons/42748?language=cpp

#include <string>
#include <vector>
#include <algorithm>

namespace Knumber {
    using namespace std;
    vector<int> solution(vector<int> array, vector<vector<int>> commands) {
        vector<int> answer = vector<int>(), result;
        for (int i = 0; i < commands.size(); i++) {
            result = vector<int>(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1]);
            sort(result.begin(), result.end());
            answer.push_back(result[commands[i][2] - 1]);
        }
        return answer;
    }
}

