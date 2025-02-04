//https://school.programmers.co.kr/learn/courses/30/lessons/84021

#include <string>
#include <vector>

using namespace std;

namespace FillInPuzzle {
    void GetPices(vector<vector<int>>& board, pair<int, int> before, vector<pair<int, int>>& pieces, int block) {
        pair<int, int> next = before;
        vector<vector<int>> move = { {1,0},{-1,0},{0,1},{0,-1} };
        for (int i = 0; i < 4; i++) {
            next.first = before.first + move[i][0];
            next.second = before.second + move[i][1];
            if (next.first == board.size() || next.first < 0 || next.second == board.size() || next.second < 0 || board[next.second][next.first] == block) {
                continue;
            }
            board[next.second][next.first] = block;
            pieces.push_back(next);
            GetPices(board, next, pieces,block);
        }
    }

    vector<int> SetPices(vector<vector<int>>& board, vector<vector<vector<bool>>>& store,int block, int pass) {
        int minX, minY, maxX, maxY;
        vector<pair<int, int>> temp;
        vector<int> counts;
        for (int i = 0; i < board.size(); i++) {
            for (int i2 = 0; i2 < board.size(); i2++) {
                if (board[i][i2] == pass) {
                    temp.clear();
                    temp.push_back(make_pair(i2, i));
                    board[i][i2] = block;
                    GetPices(board, temp[0], temp, block);
                    minX = 51;
                    minY = 51;
                    maxX = 0;
                    maxY = 0;
                    for (int i3 = 0; i3 < temp.size(); i3++) {
                        minX = min(temp[i3].first, minX);
                        minY = min(temp[i3].second, minY);
                        maxX = max(temp[i3].first, maxX);
                        maxY = max(temp[i3].second, maxY);
                    }
                    vector<vector<bool>> pices(maxX-minX+1, vector<bool>(maxY-minY+1, false));
                    for (int i3 = 0; i3 < temp.size(); i3++) {
                        temp[i3].first -= minX;
                        temp[i3].second -= minY;
                        pices[temp[i3].first][temp[i3].second] = true;
                    }
                    store.push_back(pices);
                    counts.push_back(temp.size());
                }
            }
        }

        return counts;
    }

    vector<vector<bool>> Rotation(vector<vector<bool>>& store) {
        vector<vector<bool>> result(store[0].size(), vector<bool>(store.size(),false));
        for (int i = 0; i < store.size(); i++) {
            for (int i2 = store[i].size()-1; i2 >= 0; i2--) {
                result[store[i].size()-1 - i2][i] = store[i][i2];
            }
        }
        return result;
    }

    bool EqualBlock(vector<vector<bool>>& value1, vector<vector<bool>>&  value2) {
        if (value1.size() != value2.size() || value1[0].size() != value2[0].size()) {
            return false;
        }
        for (int i = 0; i < value1.size(); i++) {
            for (int i2 = 0; i2 < value1[i].size(); i2++) {
                if (value1[i][i2] != value2[i][i2]) {
                    return false;
                }
            }
        }
        return true;
    }

    int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
        int answer = 0;
        vector<vector<vector<bool>>> store,space;
        vector<int> counts=SetPices(table, store,0,1);
        SetPices(game_board, space, 1,0);

        vector<vector<bool>> target;
        for (int i = 0; i < space.size(); i++) {
            for (int i2 = 0, flag=0; i2 < store.size() && flag==0; i2++) {
                target = store[i2];
                for (int i3 = 0; i3 < 4; i3++) {
                    if (EqualBlock(space[i], target)) {
                        answer += counts[i2];
                        store.erase(store.begin() + i2);
                        counts.erase(counts.begin() + i2);
                        flag = 1;
                        break;
                    }
                    target=Rotation(target);
                }
            }
        }
        return answer;
    }
}