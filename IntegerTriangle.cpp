//https://school.programmers.co.kr/learn/courses/30/lessons/43105

#include <string>
#include <vector>

namespace IntegerTriangle {
    using namespace std;

    int solution(vector<vector<int>> triangle) {
        int answer = 0;
        
        vector<int> result{ triangle[triangle.size() - 1] };
        int temp;
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int i2 = 0; i2 < triangle[i].size(); i2++) {
                temp = max(result[i2] + triangle[i][i2], result[i2 + 1] + triangle[i][i2]);
                result[i2] = temp;
            }
        }
        return result[0];
    }
}