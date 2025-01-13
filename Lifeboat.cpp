//https://school.programmers.co.kr/learn/courses/30/lessons/42885

#include <string>
#include <vector>
#include<algorithm>

namespace Lifeboat {
    using namespace std;
    int solution(vector<int> people, int limit) {
        int answer = 0;
        sort(people.begin(), people.end());
        int startIndex = 0, endIndex = people.size() - 1;
        while (startIndex <= endIndex) {
            if (startIndex < endIndex && people[startIndex] + people[endIndex] <= limit) {
                startIndex++;
            }
            endIndex--;
            answer++;
        }
        return answer;
    }

    //참고 코드 : https://1ets-just-do-it.tistory.com/129
}