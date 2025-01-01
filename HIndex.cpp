//https://school.programmers.co.kr/learn/courses/30/lessons/42747

#include <string>
#include <vector>
#include <algorithm>

namespace HIndex {
    using namespace std;

    int solution(vector<int> citations) {
        int answer = 0, count = 0, otherCount = 0;
        sort(citations.begin(), citations.end(), greater<>());
        for (int i = 0; i < citations.size(); i++) {
            count = i + 1;
            otherCount = citations.size() - count;
            if (count >= answer && citations[i] > answer && count >= otherCount) {
                answer = count;
            }
        }
        return answer;
    }

    /*int solution(vector<int> citations) {
        sort(citations.begin(), citations.end(), greater<int>());

        for (int i = 0; i < citations.size(); ++i) {
            if (citations[i] < i + 1) {
                return i;
            }
        }

        return citations.size();
    }*/
}
