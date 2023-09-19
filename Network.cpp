//https://school.programmers.co.kr/learn/courses/30/lessons/43162

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void search(vector<int>& checknode, vector<vector<int>>& computers, int targetindex) {
    if (find(checknode.begin(), checknode.end(), targetindex) != checknode.end()) {
        return;
    }
    checknode.push_back(targetindex);
    for (int i = 0; i < computers[targetindex].size(); i++) {
        if (i == targetindex) {
            continue;
        }
        if (find(checknode.begin(), checknode.end(), i) == checknode.end()) {
            if (computers[targetindex][i] == 1) {
                search(checknode, computers, i);
            }
        }
    }
}
int checkAlone(vector<int>& list, int target) {
    int result = 0;
    for (int i = 0; i < list.size(); i++) {
        if (list[i] == target) {
            result++;
        }
    }
    return result;
}
int solution(int n, vector<vector<int>> computers) {
    int total = 0;
    vector<int> check(computers.size(), 0);
    for (int i = 0; i < computers.size(); i++) {
        if (checkAlone(computers[i], 1) == 1) {
            total++;
            check.push_back(i);
        }
        else {
            for (int j = 0; j < computers[i].size(); j++) {
                if (i == j) {
                    continue;
                }
                if (find(check.begin(), check.end(), j) == check.end()) {
                    if (computers[i][j] != 0) {
                        search(check, computers, j);
                        total++;
                    }
                }
            }
        }
    }
    return total;
}
