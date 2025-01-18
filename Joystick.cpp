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
    �ٸ� ��� Ǯ��
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

        //index�� ���� Ž���� �Ÿ�����, ���� Ž���� �Ÿ�
        //word.size()-1 ���� Ž���ϸ�, ��� �� ����Ž���ϴ� �Ͱ� �ٸ� ���⿡ ����������.
        for (int index = 0; index < word.size(); index++) {
            for (nextAIndex = index + 1; nextAIndex < word.size() && word[nextAIndex] == 'A'; nextAIndex++);

            //���� �ε������� A�� �ƴ� ���� ���ڸ� 0���� ���������� Ž�� �� �Ÿ�
            int rZeroANextChar = word.size() - nextAIndex;

            //I���� ���� Ž�� �� �������� ���ƿ� A�� �ƴ� ���ڷ� ���������� Ž��
            int frontAndBackDist = index + index + rZeroANextChar;

            //A�� �ƴ� ���ڱ��� 0���� ���������� Ž�� �� 0���� ���ƿͼ� ����Ž��
            int backAndFrontDIst = rZeroANextChar + rZeroANextChar + index;
            //frontAndBackDist�� backAndFrontDIst���� rZeroANextChar + index�� �Ȱ����Ƿ�
            // frontAndBackDist�� backAndFrontDIst�� ��Ҹ� �����ϴ� ���� index�� rZeroANextChar��
            // �׷��⿡ �ٸ� ����� Ǯ�� min(left_right, i + len - next_i + min(i, len - next_i));���� min(i, len - next_i) �� ������ ��.

            //�� �Ÿ� �� ª�� �Ÿ� ����
            int shortDist = min(frontAndBackDist, backAndFrontDIst);

            //ó���� ���� ���� Ž���� ���� �κ� Ž�� �� ������ Ž�� �� ª�� �Ÿ� ��.
            //���Ŀ� �� ª�� �ͳ��� ��
            result = min(result, shortDist);

            //I�� ���� �þ�Ƿ�, ���� �� ������ Ž��, ������ Ž�� �� ���� Ž�� ��� Ž���ϴ� ������ ���̰� ������.
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