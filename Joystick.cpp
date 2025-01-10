//https://school.programmers.co.kr/learn/courses/30/lessons/42860

#include <string>
#include <vector>
#include <algorithm>
namespace Joystick {
    using namespace std;
    
    int GetCount(char value, char target) {
        int up, down, targetIndex, startIndex;
        targetIndex = target - 'A';
        up = down = startIndex = value - 'A';
        int upCount = 0, downCount = 0;
        while (up != targetIndex) {
            up++;
            upCount++;
            up %= 26;
        }
        while (down != targetIndex) {
            down--;
            downCount++;
            if (down < 0) {
                down = 25;
            }
        }
        if (upCount > downCount) {
            return downCount;
        }
        else {
            return upCount;
        }
    }

    int limit(int value, int size) {
        if (value< 0)return size - 1;
        return value %= size;
    }

    int tree(vector<int> buffer,int index,int answer) {
        int answer1=0, answer2=0;
        answer += buffer[index];
        buffer[index] = 0;
        if (find_if(buffer.begin(), buffer.end(), [](const int& value) {return value != 0; }) == buffer.end()) {
            return answer;
        }
        for (int i = 1,next=index+1; i < buffer.size(); i++,next++) {
            next = limit(next, buffer.size());
            if (buffer[next] != 0) {
                answer1 = tree(buffer, next, answer + i);
                break;
            }
        }
        for (int i = 1, next=index-1; i < buffer.size(); i++,next--) {
            next = limit(next, buffer.size());
            if (buffer[next] != 0) {
                answer2 = tree(buffer, next, answer + i);
                break;
            }
        }
        return min(answer1, answer2);
    }

    int solution(string name) {
        vector<int> buffer(name.size());
        for (int i = 0; i < name.size(); i++) {
            buffer[i] = GetCount('A', name[i]);
        }
        return tree(buffer, 0, 0);
    }

    

    /*
    다른 사람 풀이
    int LUT[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1 };

    int solution2(string name) {
        int answer = 0;
        for (auto ch : name)
            answer += LUT[ch - 'A'];
        int len = name.length();
        int left_right = len - 1;
        for (int i = 0; i < len; ++i) {
            int next_i = i + 1;
            while (next_i < len && name[next_i] == 'A')
                next_i++;
            left_right = min(left_right, i + len - next_i + min(i, len - next_i));
        }
        answer += left_right;
        return answer;
    }
    */

    /*
    int GetShortDist(const string& word) {
        int nextAIndex;
        int result = word.size();

        //index는 현재 탐색한 거리이자, 순차 탐색할 거리
        //word.size()-1 까지 탐색하면, 모두 다 순차탐색하는 것과 다름 없기에 종료조건임.
        for (int index = 0; index < word.size(); index++) {
            for (nextAIndex = index + 1; nextAIndex < word.size() && word[nextAIndex] == 'A'; nextAIndex++);

            //현재 인덱스에서 A가 아닌 다음 문자를 0에서 역방향으로 탐색 시 거리
            int rZeroANextChar = word.size() - nextAIndex;

            //I까지 순차 탐색 후 원점으로 돌아와 A가 아닌 문자로 역방향으로 탐색
            int frontAndBackDist = index + index + rZeroANextChar;

            //A가 아닌 문자까지 0에서 역방향으로 탐색 후 0으로 돌아와서 순차탐색
            int backAndFrontDIst = rZeroANextChar + rZeroANextChar + index;
            //frontAndBackDist와 backAndFrontDIst에서 rZeroANextChar + index는 똑같으므로
            // frontAndBackDist와 backAndFrontDIst의 대소를 결정하는 것은 index와 rZeroANextChar임
            // 그렇기에 다른 사람의 풀이 min(left_right, i + len - next_i + min(i, len - next_i));에서 min(i, len - next_i) 가 나오게 됨.

            //두 거리 중 짧은 거리 선택
            int shortDist = min(frontAndBackDist, backAndFrontDIst);

            //처음엔 완전 순차 탐색과 일정 부분 탐색 후 역방향 탐색 중 짧은 거리 비교.
            //이후엔 더 짧은 것끼리 비교
            result = min(result, shortDist);

            //I가 점점 늘어나므로, 순차 후 역방향 탐색, 역방향 탐색 후 순차 탐색 모두 탐색하는 지점의 길이가 조정됨.
        }
        return result;
    }
    int solution3(string name) {
        int answer = 0;
        for (int i = 0; i < name.size(); i++) {
            answer += min(name[i] - 'A', 'Z' - name[i] + 1);
        }

        return answer + GetShortDist(name);
    }
    */
}