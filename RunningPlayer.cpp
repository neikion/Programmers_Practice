//https://school.programmers.co.kr/learn/courses/30/lessons/42576

#include <string>
#include <vector>
#include <set>

namespace RunningPlayer {
    using namespace std;
    string solution(vector<string> participant, vector<string> completion) {
        multiset<string> table;
        for (int i = 0; i < participant.size(); i++) {
            table.insert(participant[i]);
        }

        for (int i = 0; i < completion.size(); i++) {
            multiset<string>::iterator iter = table.find(completion[i]);
            if (!(iter == table.end())) {
                table.erase(iter);
            }
        }
        return *table.begin();
    }

}
