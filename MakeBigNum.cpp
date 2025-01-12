//https://school.programmers.co.kr/learn/courses/30/lessons/42883

#include <string>
#include <vector>
//solution2에서 필요.
//#include <algorithm>
namespace MakeBigNum {

    using namespace std;
    int maxElementIndex(string& value,int k) {
        char big = 0;
        int bigIndex = 0;
        for (int i = 0; i < k; i++) {
            if (big < value[i]) {
                big = value[i];
                bigIndex = i;
            }
        }
        return bigIndex;
    }
    string solution(string number, int k) {
        int bigIndex = maxElementIndex(number, k);
        for (int i = 0; i < bigIndex; i++,k--) {
            number.erase(number.begin());
        }

        for (int i = 0; i < number.size()-1&&k!=0;) {
            if (k > 0 && number[i] < number[i + 1]) {
                number.erase(number.begin() + i);
                k--;
                i = 0;
                int test = number.size() - 1;
                continue;
            }
            i++;
        }
        for (int i=0;i<k; i++) {
            number.erase(number.end() - 1);
        }
        return number;
    }
    /*
    참조 코드 : https://school.programmers.co.kr/questions/82556
    string solution2(string number, int k) {
        string sortNumber{ number };
        sort(sortNumber.begin(), sortNumber.end());
        int removeCount = 0;
        bool removeFlag = false;
        string::iterator iter;
        while (removeCount!=k) {
            for (int i = 0; i < number.size() - 1; i++) {
                if (number[i] < number[i+1]) {
                    number.erase(number.begin()+i);
                    removeCount++;
                    removeFlag = true;
                    break;
                }
            }
            for (int i = 0; i < sortNumber.size() && !removeFlag; i++) {
                if ((iter=find(number.begin(), number.end(), sortNumber[i]))!=number.end()) {
                    number.erase(iter);
                    removeFlag = true;
                    removeCount++;
               }
            }
            removeFlag = false;
        }

        return number;
    }*/
}