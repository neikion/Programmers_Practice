//https://school.programmers.co.kr/learn/courses/30/lessons/42895

#include <string>
#include <vector>
#include <unordered_set>

namespace ExpressAsN {
    using namespace std;

    //참고 코드 : https://school.programmers.co.kr/questions/82377
    int solution(int N, int number) {
        vector<unordered_set<int>> memo;
        int answer = 0;
        int num1, num2,result=0;
        if (N == number) return 1;
        memo.push_back(unordered_set<int>());
        memo[0].insert(N);
        for (int i = 1, mul=(N*10) + N; i < 8; i++, mul = (mul * 10) + N) {
            memo.push_back(unordered_set<int>());
            if (mul == number) return i + 1;
            memo[i].insert(mul);
            for (int i2 = 0; i2 < i; i2++) {
                for (auto i3 = memo[i2].begin(); i3!=memo[i2].end(); i3++) {
                    num1 = *i3;
                    if (num1 == 0) continue;
                    for (auto i4 = memo[memo.size() - 2 - i2].begin(); i4 != memo[memo.size() - 2 - i2].end();i4++) {
                        num2 = *i4;
                        if (num2 == 0) continue;
                        result = num1 + num2;
                        if (result == number) return i+1;
                        memo[i].insert(result);
                        result = num1 - num2;
                        if (result == number) return i+1;
                        memo[i].insert(result);
                        result = num1 * num2;
                        if (result == number) return i+1;
                        memo[i].insert(result);
                        result = num1 / num2;
                        if (result == number) return i+1;
                        memo[i].insert(result);
                    }
                }
            }
        }
        return -1;
    }
}