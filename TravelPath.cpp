//https://school.programmers.co.kr/learn/courses/30/lessons/43164

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void sortList(vector<int>& list, vector<vector<string>>& tickets) {
    if (list.size() < 2) {
        return;
    }
    for (int i = 1; i < list.size(); i++) {
        if (tickets[list[i - 1]][0].compare(tickets[list[i]][0]) >= 0) {
            int temp = list[i];
            int j;
            for (j = i - 1; j > -1 && tickets[list[j]][0].compare(tickets[temp][0]) >= 0; j--) {
                if (tickets[list[j]][0].compare(tickets[temp][0]) == 0) {
                    if (tickets[list[j]][1].compare(tickets[temp][1]) > 0) {
                        list[j + 1] = list[j];
                    }
                    else {
                        break;
                    }
                }
                else {
                    list[j + 1] = list[j];
                }
            }
            list[j + 1] = temp;
        }
    }
}

vector<int> search(int target, vector<int> path, vector<vector<string>>& tickets) {
    vector<int> checklist;
    path.push_back(target);
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[target][1].compare(tickets[i][0]) == 0) {
            if (find(path.begin(), path.end(), i) != path.end()) {
                continue;
            }
            checklist.push_back(i);
        }
    }

    if (checklist.size() > 0) {
        sortList(checklist, tickets);
        for (int i = 0; i < checklist.size(); i++) {
            vector<int> result = search(checklist[i], path, tickets);
            if (result.size() == tickets.size()) {
                return result;
            }
        }
    }
    return path;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<int> startlist;
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0].compare("ICN") == 0) {
            startlist.push_back(i);
        }
    }
    sortList(startlist, tickets);
    vector<int> result;
    for (int i = 0; i < startlist.size(); i++) {
        result = search(startlist[i], vector<int>(), tickets);
        if (result.size() > 1) {
            break;
        }
    }
    for (int i = 0; i < result.size(); i++) {
        answer.push_back(tickets[result[i]][0]);
    }
    answer.push_back(tickets[result[result.size() - 1]][1]);
    return answer;
}