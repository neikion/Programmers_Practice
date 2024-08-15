//https://school.programmers.co.kr/learn/courses/30/lessons/42578

#include <string>
#include <vector>
#include <map>

namespace ClothesCombination {

	using namespace std;
    int solution(vector<vector<string>> clothes) {
        int answer = 1;
        
        map<string, int> table;
        for (int i = 0; i < clothes.size(); i++) {
            if (table.find(clothes[i][1]) == table.end()) {
                table.insert({ clothes[i][1],1 });
            }
            else {
                table[clothes[i][1]] += 1;
            }
        }
        for (auto iter = table.begin(); iter != table.end(); iter++) {
            answer *= (iter->second + 1);
        }
        answer--;
        return answer;
    }
}