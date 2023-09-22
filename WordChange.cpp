#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;
bool checkAnswer(string& a, string& b) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

bool overlapDouble(string& begin, string& check, string& target) {
    bool unique = false;
    for (int i = 0; i < begin.size(); i++) {
        if (begin[i] != check[i] && check[i] == target[i]) {
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
    if (find(words.begin(), words.end(), target) == words.end()) {
        return 0;
    }
    for (int i = 0; i < words.size(); i++) {
        check = words[i];
        if (check.size() < 3 || check.size() > 10) {
            continue;
        }
        if (overlapDouble(begin, check, target)) {
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
                cout << begin << " " << check << endl;
                if (checkclac <= stand) {
                    begin[j] = check[j];
                    answer++;
                }
            }
        }
        if (checkAnswer(begin, target)) {
            return answer;
        }
    }
    return answer;
}