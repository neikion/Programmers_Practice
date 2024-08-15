//https://school.programmers.co.kr/learn/courses/30/lessons/42586

#include <string>
#include <vector>
#include <queue>

namespace FunctionDevelop {
    using namespace std;

    vector<int> solution(vector<int> progresses, vector<int> speeds) {
        vector<int> answer;
        queue<int> task;
        for (int i = 0; i < progresses.size(); i++) {
            task.push(progresses[i]);
        }
        int target = 0;
        for (int i = 1, k = 0; task.size() > 0;) {
            if (100 - task.front() - (speeds[k] * i) <= 0) {
                target++;
                task.pop();
                k++;
            }
            else {
                if (target != 0) {
                    answer.push_back(target);
                    target = 0;
                }
                if (target == 0) {
                    i++;
                }
            }
        }
        answer.push_back(target);
        return answer;
    }
}
