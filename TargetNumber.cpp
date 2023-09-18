//https://school.programmers.co.kr/learn/courses/30/lessons/43165

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    vector<int> oper(numbers.size(), 1);
    int operindex = numbers.size() - 1;
    int sum;
    while (find(oper.begin(), oper.end(), 1) != oper.end()) {
        sum = 0;
        for (int i = 0; i < numbers.size(); i++) {
            sum += oper[i] * numbers[i];
        }
        if (sum == target) {
            answer++;
        }
        for (int k = 0; k < oper.size(); k++) {
            if (oper[operindex] == 1) {
                oper[operindex] = -1;
                for (int j = operindex + 1; j < oper.size(); j++) {
                    oper[j] = 1;
                }
                operindex = oper.size() - 1;
                break;
            }
            else {
                operindex--;
            }
        }
    }
    return answer;
}