//https://school.programmers.co.kr/learn/courses/30/lessons/86491

#include <string>
#include <vector>
#include<algorithm>

namespace CheckAnswer {
    using namespace std;
    void checkAnswer(int answer, vector<int> caseVector, int index, int& answerCount) {
        if (caseVector[index % (caseVector.size())] == answer) {
            answerCount++;
        }
    }

    vector<int> solution(vector<int> answers) {
        vector<int> answer;
        vector<int> case1{ 1,2,3,4,5 }, case2{ 2,1,2,3,2,4,2,5 }, case3{ 3,3,1,1,2,2,4,4,5,5 };
        vector<vector<int>> users;
        users.push_back(vector<int>({ 0,1 }));
        users.push_back(vector<int>({ 0,2 }));
        users.push_back(vector<int>({ 0,3 }));
        for (int i = 0; i < answers.size(); i++) {
            checkAnswer(answers[i], case1, i, users[0][0]);
            checkAnswer(answers[i], case2, i, users[1][0]);
            checkAnswer(answers[i], case3, i, users[2][0]);
        }
        int maxNum = 0;
        for (int i = 0; i < 3; i++) {
            if (maxNum < users[i][0]) {
                maxNum = users[i][0];
            }
        }
        for (int i = 0; i < 3; i++) {
            if (users[i][0] == maxNum) {
                answer.push_back(users[i][1]);
            }
        }
        sort(answer.begin(), answer.end());
        return answer;
    }

    /* another code
    
    vector<int> one = { 1,2,3,4,5 };
    vector<int> two = { 2,1,2,3,2,4,2,5 };
    vector<int> thr = { 3,3,1,1,2,2,4,4,5,5 };

    vector<int> solution(vector<int> answers) {
        vector<int> answer;
        vector<int> they(3);
        for (int i = 0; i < answers.size(); i++) {
            if (answers[i] == one[i % one.size()]) they[0]++;
            if (answers[i] == two[i % two.size()]) they[1]++;
            if (answers[i] == thr[i % thr.size()]) they[2]++;
        }
        int they_max = *max_element(they.begin(), they.end());
        for (int i = 0; i < 3; i++) {
            if (they[i] == they_max) answer.push_back(i + 1);
        }
        return answer;
    }

    */
}
