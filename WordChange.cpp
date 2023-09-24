//https://school.programmers.co.kr/learn/courses/30/lessons/43163

#include <string>
#include <vector>
#include<algorithm>
using namespace std;

bool overlapDouble(string& begin, string& check, string& target) {
    bool unique = false;
    for (int i = 0; i < begin.size(); i++) {
        if (begin[i] == check[i]) {
            if (!unique) {
                unique = true;
            }
            else {
                return true;
            }
        }
    }
    return false;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    string check;
    bool checked = true;
    int ibefore = 99;
    string sbefore;
    if (find(words.begin(), words.end(), target) == words.end()) {
        return 0;
    }
    while (checked) {
        checked = false;
        for (int i = 0; i < words.size(); i++) {
            check = words[i];
            if (check.size() < 3 || check.size() > 10) {
                continue;
            }
            if (!overlapDouble(begin, check, target)) {
                continue;
            }
            if (begin.compare(check) == 0) {
                continue;
            }
            for (int j = 0; j < check.size(); j++) {
                if (begin[j] != check[j] && begin[j] != target[j]) {
                    int itarget = (int)target[j];
                    int ibegin = (int)begin[j];
                    int icheck = (int)check[j];
                    int stand, checkclac;
                    if (ibegin > itarget) {
                        stand = ibegin - itarget;
                    }
                    else {
                        stand = itarget - ibegin;
                    }
                    if (icheck > itarget) {
                        checkclac = icheck - itarget;
                    }
                    else {
                        checkclac = itarget - icheck;
                    }
                    if (checkclac <= stand) {
                        if (checkclac < ibefore) {
                            ibefore = checkclac;
                            sbefore = check;
                        }
                    }
                }
            }
            if (ibefore != 99) {
                begin = sbefore;
                answer++;
                ibefore = 99;
                checked = true;
            }
            if (begin.compare(target)==0) {
                return answer;
            }
        }
    }
    return answer;
}