//https://school.programmers.co.kr/learn/courses/30/lessons/12909?language=cpp

#include<string>
#include <stack>

namespace CorrectParenthesises {
    using namespace std;
    bool solution(string s)
    {
        stack<char> data;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '\(') {
                data.push(s[i]);
            }
            else {
                if (data.size() > 0) {
                    data.pop();
                }
                else {
                    return false;
                }
            }
        }
        if (data.size() > 0) {
            return false;
        }
        return true;
    }
}