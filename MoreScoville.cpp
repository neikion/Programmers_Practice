//https://school.programmers.co.kr/learn/courses/30/lessons/42626

#include <string>
#include <vector>
#include <queue>

namespace MoreScoville {
    using namespace std;

    int solution(vector<int> scoville, int K) {
        int answer = 0;
        priority_queue<int, vector<int>, greater<int>> queue;
        for (int i = 0; i < scoville.size(); i++) {
            queue.push(scoville[i]);
        }
        for (int a = 0, b = 0; queue.top() < K; answer++) {
            a = queue.top();
            queue.pop();
            b = queue.top();
            queue.pop();
            queue.push(a + (b * 2));
            if (queue.size() == 1 && queue.top() < K) {
                return -1;
            }
        }
        return answer;
    }
}

