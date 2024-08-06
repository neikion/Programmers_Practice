//https://school.programmers.co.kr/learn/courses/30/lessons/42839

#include <string>
#include <vector>
#include<algorithm>
#include<math.h>

namespace FindPrimeNumber {

    using namespace std;

    bool IsPrime(int value) {
        if (value < 2) {
            return false;
        }
        if (value == 2) {
            return true;
        }
        if (value % 2 == 0) {
            return false;
        }
        for (int i = 2; i <= sqrt(value); i++) {
            if (value % i == 0) {
                return false;
            }
        }
        return true;
    }


    int GetNum(vector<int> value) {
        int result = 0;
        for (int i = 0; i < value.size(); i++) {
            result *= 10;
            result += value[i];
        }
        return result;
    }
    void FindPrime(vector<int> target, vector<int> part, vector<int>& result) {
        if (part.size() == 0) {
            return;
        }
        for (int k = 0; k < part.size(); k++) {
            int chooseNum = part[k];
            vector<int> tempPart(part);
            tempPart.erase(tempPart.begin() + k);
            for (int i = 0,limit=target.size(); i <= limit; i++) {
                vector<int> tempTarget(target);
                tempTarget.insert(tempTarget.begin() + i, chooseNum);
                int tempint = GetNum(tempTarget);
                if (IsPrime(tempint)) {
                    result.push_back(tempint);
                }
                FindPrime(tempTarget, tempPart, result);
            }
        }
    }

    int solution(string numbers) {
        int answer = 0;
        vector<int> part;
        
        for (int i = 0; i < numbers.size(); i++) {
            part.push_back(numbers[i] - '0');
        }
        sort(part.begin(), part.end());

        vector<int> result;
        for (int i = 0; i < part.size(); i++) {
            vector<int> partv(part);
            vector<int> targetv;
            partv.erase(partv.begin() + i);
            targetv.push_back(part[i]);
            if (IsPrime(part[i])) {
                result.push_back(part[i]);
            }
            FindPrime(targetv, partv, result);
        }

        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        answer = result.size();
        return answer;
    }


}