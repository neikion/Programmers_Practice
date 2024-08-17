//https://school.programmers.co.kr/learn/courses/30/lessons/42628


#include <string>
#include <vector>
#include <set>


namespace DualPriorityQueue {
    using namespace std;

    vector<int> solution(vector<string> operations) {
        vector<int> answer;
        multiset<int> numset;
        for (int i = 0; i < operations.size(); i++) {
            char oper = operations[i][0];
            int value = atoi(operations[i].substr(2, operations[i].size()).c_str());
            if (oper == 'I') {
                numset.insert(value);
            }
            else {
                if (numset.size() == 0) {
                    continue;
                }
                if (value < 0) {
                    numset.erase(*numset.begin());
                }
                else {
                    numset.erase(*numset.rbegin());
                }
            }
        }
        if (numset.size() == 0) {
            answer.push_back(0);
            answer.push_back(0);
        }
        else {
            answer.push_back(*numset.rbegin());
            answer.push_back(*numset.begin());
        }
        return answer;
    }
}
