#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
void resetTargetList(vector<int>& list, vector<vector<string>>& tickets) {
    for (int i = 0; i < list.size(); i++) {
        for (int j = i; j > -1; j--) {
            if (tickets[list[i]][1].compare(tickets[list[j]][1]) < 0) {
                int temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}
vector<int> search(int target, vector<int> path, vector<vector<string>>& tickets) {
    if (path.size() == tickets.size()) {
        return path;
    }
    int check = -1;

    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[target][1].compare(tickets[i][0]) == 0) {
            if (find(path.begin(), path.end(), i) != path.end()) {
                continue;
            }
            if (check == -1) {
                check = i;
            }
            else if (tickets[check][0].compare(tickets[i][0]) > 0) {
                check = i;
            }
        }
    }
    path.push_back(check);
    if (path.size() == tickets.size()) {
        return path;
    }
    return search(check, path, tickets);;
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    int target = -1;
    vector<int> startlist;
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0].compare("ICN") == 0) {
            startlist.push_back(i);
            if (target == -1) {
                target = i;
            }
            else if (tickets[target][1].compare(tickets[i][1]) > 0) {
                target = i;
            }
        }
    }

    resetTargetList(startlist,tickets);
    vector<int> result;
    for (int i = 0; i < startlist.size(); i++) {
        result = search(startlist[i], vector<int>{startlist[i]}, tickets);
        if (result.size() > 0) {
            break;
        }
    }
    for (int i = 0; i < result.size(); i++) {
        answer.push_back(tickets[result[i]][0]);
    }
    answer.push_back(tickets[result[result.size() - 1]][1]);
    return answer;
}