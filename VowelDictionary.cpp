//https://school.programmers.co.kr/learn/courses/30/lessons/84512?language=cpp

#include <string>
#include <vector>

namespace VowelDictionary {
    using namespace std;
   char find(int value) {
        switch (value) {
        case 1:
            return 'A';
        case 2:
            return 'E';
        case 3:
            return 'I';
        case 4:
            return 'O';
        case 5:
            return 'U';
        }
        return ' ';
    }

    bool tree(string& goal, string& buffer, int index, int& answer) {
        buffer.push_back(' ');
        for (int i = 1; i < 6; i++) {
            answer++;
            buffer[index] = find(i);
            if (goal == buffer) {
                return true;
            }
            if (index < 4 && tree(goal, buffer, index + 1, answer)) {
                return true;
            }
        }
        buffer.erase(buffer.begin() + index);
        return false;
    }

    int solution(string word) {
        int answer = 0;
        string temp;
        tree(word, temp, 0, answer);
        return answer;
    }
}