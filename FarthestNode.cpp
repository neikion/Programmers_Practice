//https://school.programmers.co.kr/learn/courses/30/lessons/49189

#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

namespace FarthestNode {
    vector<int> tree(vector<vector<int>>& map) {
        queue<pair<int, int>> wait{ {make_pair(1, 0)} };
        unordered_set<int> before{1};
        pair<int, int> nowNode;
        vector<int> nodeLength(map.size());
        while (wait.size() > 0) {
            nowNode = wait.front();
            for (int i = 0, target = 0; i < map[nowNode.first].size(); i++) {
                target = map[nowNode.first][i];
                if (before.find(target) == before.end()) {
                    before.insert(target);
                    nodeLength[target] = nowNode.second + 1;
                    wait.push(make_pair(target, nowNode.second + 1));
                }
            }
            wait.pop();
        }
        return nodeLength;
    }

    int solution(int n, vector<vector<int>> edge) {
        int answer = 0, big = 0;
        vector<vector<int>> line(n + 1, vector<int>());

        for (int i = 0, small = 0, big = 0; i < edge.size(); i++) {
            small = min(edge[i][0], edge[i][1]);
            big = max(edge[i][0], edge[i][1]);
            line[small].push_back(big);
            line[big].push_back(small);
        }
        vector<int> result = tree(line);
        for (int i : result) {
            big = max(i, big);
        }
        for (int i : result) {
            if (i == big) answer++;
        }
        return answer;
    }
}