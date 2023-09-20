//https://school.programmers.co.kr/learn/courses/30/lessons/1844

#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int total;

void search(vector<vector<int>>& maps, vector<vector<int>> path, int target[2], int pathcount) {
    path[target[0]][target[1]] = 0;
    pathcount++;
    if (target[0] == maps.size() - 1 && target[1] == maps[maps.size() - 1].size() - 1) {
        if (total > pathcount) {
            total = pathcount;
        }
    }
    int pos[2];
    for (int i = -1; i < 2; i += 2) {
        for (int j = 0; j < 2; j++) {
            if (j == 0) {
                pos[0] = target[0] + i;
                pos[1] = target[1];
            }
            else {
                pos[0] = target[0];
                pos[1] = target[1] + i;
            }
            if (pos[0] < 0 || pos[1] < 0) {
                continue;
            }
            if (pos[0] > maps.size() - 1 || pos[1] > maps[pos[0]].size() - 1) {
                continue;
            }
            if (path[pos[0]][pos[1]] == 0) {
                continue;
            }
            search(maps, path, pos, pathcount);
        }
    }
}
int solution(vector<vector<int> > maps)
{
    int mypos[2] = { 0,0 };
    total = (maps.size() * maps[maps.size() - 1].size()) + 1;
    search(maps, maps, mypos, 0);
    if (total == (maps.size() * maps[maps.size() - 1].size()) + 1) {
        total = -1;
    }
    return total;
}