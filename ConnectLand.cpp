//https://school.programmers.co.kr/learn/courses/30/lessons/42861

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

namespace ConnectLand {
    struct QueueComapre
    {
        bool operator()(const pair<int,int>& value1, const pair<int, int>& value2) {
            return value1.second > value2.second;
        }
    };
    bool vectorCompare(const vector<int>& value1, const vector<int>& value2) {
        return value1[2] < value2[2];
    }

    int solution2(int n, vector<vector<int>> costs) {
        int answer = 0;
        vector<vector<pair<int, int>>> lands(n);
        vector<int> history;
        priority_queue<pair<int, int>, vector<pair<int, int>>, QueueComapre> lines;
        sort(costs.begin(), costs.end(), vectorCompare);
        for (int i = 0; i < costs.size(); i++) {
            lands[costs[i][0]].push_back(make_pair(costs[i][1], costs[i][2]));
            lands[costs[i][1]].push_back(make_pair(costs[i][0], costs[i][2]));
        }
        int target = 0;
        history.push_back(target);
        while (history.size() != n) {
            for (int i = 0; i < lands[target].size(); i++) {
                lines.push(lands[target][i]);
            }
            for (int i = 0, size = lines.size(); i < size; i++) {
                if (find(history.begin(), history.end(), lines.top().first) == history.end()) {
                    target = lines.top().first;
                    history.push_back(target);
                    answer += lines.top().second;
                    lines.pop();
                    break;
                }
                lines.pop();
            }
        }
        return answer;
    }

    class node {
    public:
        int value;
        vector<pair<int,int>> next;
    };
    
    int solution1(int n, vector<vector<int>> costs) {
        int answer = 0;
        vector<node> lands;
        vector<int> history;
        priority_queue<pair<int, int>, vector<pair<int, int>>, QueueComapre> lines;
        for (int i = 0; i < n; i++) {
            lands.push_back(node{ i });
        }
        sort(costs.begin(), costs.end(), vectorCompare);
        int land;
        int nextLand;
        for (int i = 0; i < costs.size(); i++) {
            land = min(costs[i][0], costs[i][1]);
            nextLand = max(costs[i][0], costs[i][1]);
            lands[land].next.push_back(make_pair(nextLand, costs[i][2]));
            lands[nextLand].next.push_back(make_pair(land, costs[i][2]));
        }
        node target = lands[0];
        history.push_back(target.value);
        while (history.size() != n) {
            for (int i = 0; i < target.next.size(); i++) {
                lines.push(target.next[i]);
            }
            for (int i = 0,size=lines.size(); i < size; i++) {
                if (find(history.begin(), history.end(), lines.top().first) == history.end()) {
                    target = lands[lines.top().first];
                    history.push_back(target.value);
                    answer += lines.top().second;
                    lines.pop();
                    break;
                }
                lines.pop();
            }
        }
        return answer;
    }
    
    //다른 사람 코드
    /*
    int getParent(int* d, int value) {
        if (value == d[value]) {
            return value;
        }
        else return d[value] = getParent(d,d[value]);
    }

    bool compare(vector<int> a, vector<int> b) {
        return a[2] < b[2];
    }

    int solution(int n, vector<vector<int>> costs) {
        int d[101];
        int answer = 0;
        for (int i = 0; i < n; i++) {
            d[i] = i;
        }
        sort(costs.begin(), costs.end(), compare);
        for (int i = 0; i < costs.size(); i++) {
            int start = getParent(d,costs[i][0]);
            int end = getParent(d,costs[i][1]);
            int cost = costs[i][2];

            if (start != end) {
                d[end] = start;

                answer += cost;
            }
        }


        return answer;
    }
    */
}