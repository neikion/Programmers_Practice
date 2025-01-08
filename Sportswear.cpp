//https://school.programmers.co.kr/learn/courses/30/lessons/42862

#include <string>
#include <vector>
#include <algorithm>
namespace Sportwear {

    using namespace std;
    int solution(int n, vector<int> lost, vector<int> reserve) {
        int answer = n - lost.size();
        sort(lost.begin(), lost.end());
        vector<int>::iterator iter;
        for (int i = lost.size() - 1; i >= 0; i--) {
            if ((iter = find(reserve.begin(), reserve.end(), lost[i])) != reserve.end()) {
                reserve.erase(iter);
                lost.erase(lost.begin() + i);
                answer++;
            }
        }
        for (int i = 0; i < lost.size(); i++) {
            if ((iter = find(reserve.begin(), reserve.end(), lost[i] - 1)) != reserve.end() ||
                (iter = find(reserve.begin(), reserve.end(), lost[i] + 1)) != reserve.end()
                ){
                reserve.erase(iter);
                answer++;
            }
        }
        return answer;
    }
    /*
    다른 사람 풀이 1
    int solution2(int n, vector<int> lost, vector<int> reserve) {
        int student[35]{0};
        int answer = 0;
        for (int i : reserve) student[i] += 1;
        for (int i : lost) student[i] += -1;
        for (int i = 1; i <= n; i++) {
            if (student[i] == -1) {
                if (student[i - 1] == 1)
                    student[i - 1] = student[i] = 0;
                else if (student[i + 1] == 1)
                    student[i] = student[i + 1] = 0;
            }
        }
        for (int i = 1; i <= n; i++)
            if (student[i] != -1) answer++;

        return answer;
    }
    */
}