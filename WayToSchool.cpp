//https://school.programmers.co.kr/learn/courses/30/lessons/42898

#include <string>
#include <vector>

namespace WayToSchool {

    using namespace std;

    //참고 코드
    // https://dev-note-97.tistory.com/141
    // https://school.programmers.co.kr/questions/46669
    int solution(int m, int n, vector<vector<int>> puddles) {
        vector<vector<int>> list(m, vector<int>(n, 0));
        for (int i = 0; i < puddles.size(); i++) {
            list[puddles[i][0]-1][puddles[i][1]-1] = -1;
        }
        for (int i = m-1; i >=0; i--) {
            for (int i2 = n - 1; i2 >= 0; i2--) {
                if (i == m-1 && i2 == n-1) {
                    list[i][i2] = 1;
                }
                else if (list[i][i2] == -1) {
                    list[i][i2] = 0;
                }
                else if (i==m-1) {
                    list[i][i2] = list[i][i2+1];
                }
                else if (i2 == n-1) {
                    list[i][i2] = list[i+1][i2];
                }
                else {
                    list[i][i2] = list[i + 1][i2] + list[i][i2+1];
                    list[i][i2] %= 1000000007;
                }
            }
        }
        return list[0][0];
    }
    /*
    다른 사람 풀이
    int solution(int m, int n, vector<vector<int>> puddles) {
        int answer = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (auto p : puddles) dp[p[0]][p[1]] = -1;

        dp[1][1] = 1;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (dp[i][j] == -1) dp[i][j] = 0;
                else dp[i][j] += (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
            }
        }

        return answer = dp[m][n];
    }*/
}