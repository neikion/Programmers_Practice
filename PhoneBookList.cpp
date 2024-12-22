//https://school.programmers.co.kr/learn/courses/30/lessons/42577?language=cpp

#include <string>
#include <vector>
#include<algorithm>
#include <iostream>

namespace PhoneBookList {
    using namespace std;
    class Tree {
    public:
        bool finish;
        vector<Tree*> list;
        Tree() : finish(false), list(vector<Tree*>(10)) {}
        bool Insert(string* value, int index = 0) {
            if (finish) return false;
            int targetIndex = (*value)[index] - '0';
            if (list[targetIndex] == NULL) {
                list[targetIndex] = new Tree();
            }
            if (++index < value->size()) {
                return list[targetIndex]->Insert(value, index);
            }
            if (list[targetIndex] != NULL && list[targetIndex]->finish) return false;
            list[targetIndex]->finish = true;
            return true;
        }
        ~Tree() {
            for (int i = 0; i < list.size(); i++) {
                if (list[i] != NULL) {
                    delete list[i];
                }
            }
        }
    };

    bool solution(vector<string> phone_book) {
        Tree table;
        sort(phone_book.begin(), phone_book.end());
        for (int i = 0; i < phone_book.size(); i++) {
            if (!table.Insert(&phone_book[i])) {
                return false;
            }
        }
        return true;
    }
}