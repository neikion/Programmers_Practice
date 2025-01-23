//https://school.programmers.co.kr/learn/courses/30/lessons/42897

#include <string>
#include <vector>

using namespace std;

namespace Thievery {
    //참고 코드
    // https://school.programmers.co.kr/questions/31576
    // https://school.programmers.co.kr/questions/81654
    int solution(vector<int> money) {
        vector<int> result1(money.size(),0), result2(money.size()+1, 0);
        result1[1] = money[0];
        for (int i = 2; i < result1.size(); i++) {
            result1[i] = max(result1[i - 2] + money[i - 1], result1[i - 1]);
        }
        
        for (int i = 2; i < result2.size(); i++) {
            result2[i] = max(result2[i - 2] + money[i - 1], result2[i - 1]);
        }
        return max(result1[result1.size()-1], result2[result2.size() - 1]);
    }
}