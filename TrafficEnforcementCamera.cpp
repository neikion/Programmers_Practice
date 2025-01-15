//https://school.programmers.co.kr/learn/courses/30/lessons/42884

#include <string>
#include <vector>
#include <algorithm>


namespace TrafficEnforcementCamera {
    using namespace std;
    //설명 참고 : https://school.programmers.co.kr/questions/27135
    int solution(vector<vector<int>> routes) {
        int answer = 0;
        sort(routes.begin(), routes.end(), [](const vector<int>& value1, const vector<int>& value2) {
            return value1[1] < value2[1];
            });
        int position = -30001;
        for (int i = 0; i < routes.size(); i++) {
            if (routes[i][0] <= position && routes[i][1] >= position) {
                continue;
            }
            if (routes[i][1] > position) {
                position = routes[i][1];
                answer++;
            }
        }
        return answer;
    }
}