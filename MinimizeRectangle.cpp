//https://school.programmers.co.kr/learn/courses/30/lessons/86491

#include <string>
#include <vector>

namespace MinimizeRectangle {
    using namespace std;
    int solution(vector<vector<int>> sizes) {
        int answer = 0;
        int maxRow = 0;
        int maxCol = 0;
        for (int i = 0; i < sizes.size(); i++) {
            if (sizes[i][0] < sizes[i][1]) {
                int temp = sizes[i][0];
                sizes[i][0] = sizes[i][1];
                sizes[i][1] = temp;
            }
            if (sizes[i][0] > maxRow) maxRow = sizes[i][0];
            if (sizes[i][0] > maxCol) maxCol = sizes[i][1];
        }
        answer = maxRow * maxCol;
        return answer;
    }
}
