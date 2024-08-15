//https://school.programmers.co.kr/learn/courses/30/lessons/42587

#include <string>
#include <vector>
#include <algorithm>

namespace Process {
    using namespace std;

    int solution(vector<int> priorities, int location) {
        int answer = 0;
        for (int i = 0; true;i++) {
            answer++;
            for (int k = 0; k < priorities.size(); k++) {
                if (priorities[i % priorities.size()] == *max_element(priorities.begin(),priorities.end())) {
                    break;
                }
                i++;
            }
            priorities[i% priorities.size()] = 0;
            if ((i% priorities.size()) == location) {
                break;
            }
        }
        return answer;
    }
}