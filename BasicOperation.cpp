//https://school.programmers.co.kr/learn/courses/30/lessons/1843?language=cpp

#include <vector>
#include <string>
#include<cmath>
#include<limits.h>

namespace BasicOperation {
    using namespace std;

    int isPlus(string value) {
        if (value[0]=='+') {
            return true;
        }
        return false;
    }

    //참조 코드 : https://velog.io/@longroadhome/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-LV.4-%EC%82%AC%EC%B9%99%EC%97%B0%EC%82%B0
    int solution(vector<string> arr)
    {
        int size = (arr.size() / 2) +1;
        vector<vector<int>> maxMemo(size,vector<int>(size,INT_MIN));
        vector<vector<int>> minMemo(size, vector<int>(size,INT_MAX));

        for (int i = 0; i < size; i++) {
            maxMemo[i][i] = stoi(arr[i*2]);
            minMemo[i][i] = stoi(arr[i*2]);
        }

        for (int i = 1; i < maxMemo.size(); i++) {
            for (int i2 = 0; i2+i < maxMemo[i].size(); i2++) {
                for (int i3 = i2; i3 < i2+i; i3++) {
                    if (isPlus(arr[(i3 * 2) + 1])) {
                        maxMemo[i2][i2 + i] = max(maxMemo[i2][i2 + i], maxMemo[i2][i3] + maxMemo[i3 + 1][i2 + i]);
                        minMemo[i2][i2 + i] = min(minMemo[i2][i2 + i], minMemo[i2][i3] + minMemo[i3 + 1][i2 + i]);
                    }
                    else {
                        maxMemo[i2][i2 + i] = max(maxMemo[i2][i2 + i], maxMemo[i2][i3] - minMemo[i3 + 1][i2 + i]);
                        minMemo[i2][i2 + i] = min(minMemo[i2][i2 + i], minMemo[i2][i3] - maxMemo[i3 + 1][i2 + i]);
                    }
                }
            }
        }
        
        return maxMemo[0][maxMemo[0].size() - 1];
    }
}