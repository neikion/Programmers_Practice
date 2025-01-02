//https://school.programmers.co.kr/learn/courses/30/lessons/42842

#include <string>
#include <vector>

namespace Carpet {
    using namespace std;

    vector<int> solution(int brown, int yellow) {
        vector<int> answer{ 0,0 };
        for (int i = 1; (i*i) <= yellow; i++) {
            if (yellow%i== 0) {
                answer[0] = (yellow / i)+2;
                answer[1] = i+2;
                if ((((answer[0] + answer[1]) * 2) -4) == brown) {
                    return answer;
                }
            }
        }
        return answer;
    }
    /* 참고한 코드 : https://school.programmers.co.kr/questions/74684
    vector<int> solution2(int brown, int yellow) {
        vector<int> answer;
        for (int i = 1; i * i <= yellow; i++) {
            if (yellow % i > 0) continue;

            int inner_w = yellow / i;
            int inner_h = i;
            if ((inner_w + 2) * 2 + (inner_h + 2) * 2 - 4 == brown) {
                answer.push_back(inner_w + 2);
                answer.push_back(inner_h + 2); 
                break;
            }
        }
        return answer;
    }
    */
}