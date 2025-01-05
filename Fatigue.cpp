//https://school.programmers.co.kr/learn/courses/30/lessons/87946

#include <string>
#include <vector>

namespace Fatique {
    using namespace std;
    int tree(vector<vector<int>> dungeons, int k, int answer) {
        int result = answer;
        for (int i = 0; i < dungeons.size(); i++) {
            if (dungeons[i][0] <= k && dungeons[i][1] <= k) {
                vector<vector<int>> clone(dungeons.begin(), dungeons.end());
                clone.erase(clone.begin() + i);
                int temp = tree(clone, k - dungeons[i][1], answer + 1);
                if (temp >= result) {
                    result = temp;
                }
            }
        }
        return result;
    }

    int solution(int k, vector<vector<int>> dungeons) {
        int answer = 0;
        return tree(dungeons, k, 0);
    }
}
