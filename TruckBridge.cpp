//https://school.programmers.co.kr/learn/courses/30/lessons/42583

#include <string>
#include <vector>
#include <queue>


namespace BusBridge {
    using namespace std;
    int solution(int bridge_length, int weight, vector<int> truck_weights) {
        int answer = 0, bridgeWeight = 0, goalIndex = 0, waitIndex = 0;
        vector<pair<int, int>> bridge;

        while (goalIndex < truck_weights.size()) {
            for (int i = 0; i < bridge.size(); i++) {
                bridge[i].second++;
            }
            
            for (int i = bridge.size() - 1; i > -1; i--) {
                if (bridge[i].second > bridge_length) {
                    bridgeWeight -= bridge[i].first;
                    bridge.erase(bridge.begin() + i);
                    goalIndex++;
                }
            }
            while (waitIndex < truck_weights.size() && bridge.size() <= bridge_length && bridgeWeight + truck_weights[waitIndex] <= weight) {
                bridge.push_back(make_pair(truck_weights[waitIndex], 1));
                bridgeWeight += truck_weights[waitIndex];
                waitIndex++;
                if (waitIndex < truck_weights.size() && bridge.size() <= bridge_length && bridgeWeight + truck_weights[waitIndex] <= weight) {
                    for (int i = 0; i < bridge.size(); i++) {
                        bridge[i].second++;
                    }
                    answer++;
                }
            }
            answer++;
        }
        return answer;
    }

    /*int solution2(int bridge_length, int weight, vector<int> truck_weights) {
        int answer = 0, count = 0, time = 0, allWeight=0;
        queue<pair<int, int>> moving;
        while (true) {
            if (weight >= allWeight + truck_weights[count]) {
                moving.push(make_pair(truck_weights[count], bridge_length + 1 + time));
                allWeight += truck_weights[count];
                count++;
            }
            if (count >= truck_weights.size()) {
                return moving.back().second;
            }
            else
            {
                time++;
                if (moving.front().second == time + 1) {
                    allWeight -= moving.front().first;
                    moving.pop();
                }
            }
        }
        return answer;
    }*/
}