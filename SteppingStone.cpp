//https://school.programmers.co.kr/learn/courses/30/lessons/43236

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

namespace SteppingStone {

    //Âü°í : https://school.programmers.co.kr/questions/31861
    int solution(int distance, vector<int> rocks, int n) {
        int answer = 0;
        sort(rocks.begin(), rocks.end());
        int high = distance, low = 0, mid, pro;
        bool passFlag;
        while (low <= high) {
            mid = (low + high) / 2;
            passFlag = true;
            for (int i = 0, start = 0, pass = 0; i <= rocks.size(); i++) {
                if (i == rocks.size()) {
                    pro = distance - start;
                }
                else {
                    pro = rocks[i] - start;
                }
                if (pro < mid) {
                    if (pass < n) {
                        pass++;
                        continue;
                    }
                    else {
                        passFlag = false;
                        break;
                    }
                }
                if (i < rocks.size()) {
                    start = rocks[i];
                }
            }
            if (!passFlag) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
                answer = max(mid, answer);
            }
        }
        return answer;
    }

}