//https://school.programmers.co.kr/learn/courses/30/lessons/1845?language=cpp

#include <vector>
#include <map>


namespace Phonekemon {
    using namespace std;
    int solution(vector<int> nums)
    {
        map<int, int> monKind;
        for (int i = 0; i < nums.size(); i++) {
            monKind[nums[i]] += 1;
        }
        return monKind.size() < nums.size() / 2 ? monKind.size() : nums.size() / 2;
    }

}