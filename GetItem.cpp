//https://school.programmers.co.kr/learn/courses/30/lessons/87694

#include <string>
#include <vector>
#include <queue>

using namespace std;

namespace GetItem {

    //참고 방법 : https://school.programmers.co.kr/questions/32456
    int GetOverlapRect(int x, int y, vector <vector<int>>& rect,int ignoreRect) {
        vector<int> target;
        for (int i = 0; i < rect.size(); i++) {
            if (ignoreRect == i) continue;
            target = rect[i];
            if (x > target[0] && y > target[1] && x < target[2] && y < target[3]) {
                return i;
            }
        }
        return -1;
    }
    int GetRect(pair<int, int> value, vector <vector<int>>& rect, int ignoreRect) {
        vector<int> target;
        for (int i = 0; i < rect.size(); i++) {
            if (ignoreRect == i) continue;
            target = rect[i];
            if (value.first >= target[0] && value.second >= target[1] && value.first <= target[2] && value.second <= target[3]) {
                return i;
            }
        }
        return -1;
    }
    int tree(vector<vector<int>>& map, pair<int,int> before, queue<pair<pair<int,int>,int>> checkList, pair<int,int> item, int nowRect) {
        pair<int, int> next;
        pair<pair<int, int>, int> now;
        map[before.first][before.second] = 0;
        while (checkList.size() > 0) {
            now = checkList.front();
            checkList.pop();
            next = now.first;
            if (item == now.first) {
                return now.second/2;
            }
            next.first = now.first.first + 1;
            if (next.first<map.size() && map[next.first][next.second] != 0) {
                checkList.push(make_pair(next, now.second+1));
            }
            next.first = now.first.first - 1;
            if (next.first>0 && map[next.first][next.second] != 0) {
                checkList.push(make_pair(next, now.second+1));
            }
            next = now.first;
            next.second = now.first.second + 1;
            if (next.second<map[next.first].size()&& map[next.first][next.second] != 0) {
                checkList.push(make_pair(next, now.second+1));
            }
            next.second = now.first.second - 1;
            if (next.second > 0&& map[next.first][next.second] != 0) {
                checkList.push(make_pair(next, now.second+1));
            }
            map[now.first.first][now.first.second] = 0;
        }
    }
    int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
        vector<vector<int>> map(101, vector<int>(101, 0));
        for (int i = 0; i < rectangle.size(); i++) {
            for (int i2 = 0; i2 < rectangle[i].size(); i2++) {
                rectangle[i][i2] *= 2;
            }
        }
        for (int i = 0; i < rectangle.size(); i++) {
            for (int i2 = rectangle[i][0]; i2 <= rectangle[i][2]; i2++) {
                if (GetOverlapRect(i2, rectangle[i][1], rectangle,-1) == -1) {
                    map[i2][rectangle[i][1]] = 1;
                }
                if (GetOverlapRect(i2, rectangle[i][3], rectangle, -1) == -1) {
                    map[i2][rectangle[i][3]] = 1;
                }
            }
            for (int i3 = rectangle[i][1]; i3 <= rectangle[i][3]; i3++) {
                if (GetOverlapRect(rectangle[i][0], i3, rectangle, -1) == -1) {
                    map[rectangle[i][0]][i3] = 1;
                }
                if (GetOverlapRect(rectangle[i][2], i3, rectangle, -1) == -1) {
                    map[rectangle[i][2]][i3] = 1;
                }
            }
        }
        pair<int, int> pos = make_pair(characterX * 2, characterY * 2);
        return tree(map, pos, queue<pair<pair<int, int>, int>>{{make_pair(pos, 0)}}, make_pair(itemX * 2, itemY * 2), GetRect(pos, rectangle, -1));
    }
}