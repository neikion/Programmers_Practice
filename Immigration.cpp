//https://school.programmers.co.kr/learn/courses/30/lessons/43238

#include <string>
#include <vector>
#include <algorithm>

namespace Immigration {

    using namespace std;
    //참고 코드 : https://suhyeokeee.tistory.com/183
    long long solution(int n, vector<int> times) {
        sort(times.begin(), times.end());
        long long start = times[0], end = (long long)times[times.size() - 1] * n, mid=0, target=0;
        long long result=end;
        while (start<=end) {
            mid = start+((end-start)/2);
            target = 0;
            for (long long i = 0; i < times.size() && target < n ; i++) {
                target += mid / times[i];
            }
            if (target >= n) {
                result = min(mid, result);
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return result;
    }
}