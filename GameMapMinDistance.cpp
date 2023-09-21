//https://school.programmers.co.kr/learn/courses/30/lessons/1844

#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class node {
public:
    int x;
    int y;
    node() = default;
    node(int ix, int iy) :x(ix), y(iy) {

    }
};
int search(vector<vector<int>>& maps, vector<vector<int>> path) {
    path[0][0] = 1;
    int pos[2];
    queue<node> waiting;
    waiting.push(node(0, 0));
    node targetnode, value;
    while (waiting.size() > 0) {
        for (int i = -1; i < 2; i += 2) {
            value = waiting.front();
            for (int j = 0; j < 2; j++) {
                if (j == 0) {
                    targetnode.x = value.x + i;
                    targetnode.y = value.y;
                }
                else {
                    targetnode.x = value.x;
                    targetnode.y = value.y + i;
                }
                if (targetnode.x < 0 || targetnode.y < 0) {
                    continue;
                }
                if (targetnode.x >= maps.size() || targetnode.y >= maps[targetnode.x].size()) {
                    continue;
                }
                if (maps[targetnode.x][targetnode.y] == 1 && path[targetnode.x][targetnode.y] + 1 < path[value.x][value.y]) {
                    path[targetnode.x][targetnode.y] = path[value.x][value.y] + 1;
                    if (targetnode.x == maps.size() - 1 && targetnode.y == maps[maps.size() - 1].size() - 1) {
                        return path[maps.size() - 1][maps[maps.size() - 1].size() - 1];
                    }
                    waiting.push(node(targetnode.x, targetnode.y));
                }
            }
        }
        waiting.pop();
    }
    return path[maps.size() - 1][maps[maps.size() - 1].size() - 1];
}

int solution(vector<vector<int> > maps)
{
    return search(maps, vector<vector<int>>(maps.size(), vector<int>(maps[0].size(), -1)));
}