//https://school.programmers.co.kr/learn/courses/30/lessons/42579

#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

namespace BestAlbum {
    using namespace std;

    struct SingInfo {
        int play;
        int id;
        SingInfo(int id,int play) :id(id),play(play) { }
    };
    struct SingCompare {
        bool operator()(const SingInfo& value1, const SingInfo& value2) const {
            if (value1.play == value2.play) {
                return value1.id < value1.id;
            }
            return value1.play> value2.play;
        }
    };
    struct GenresTable {
        string name;
        multiset<SingInfo,SingCompare> sings;
        int GenresPlay;
        GenresTable(string name) : name(name),sings(multiset<SingInfo,SingCompare>()),GenresPlay(0) {

        }
    };

    bool GenresPlayCompare(const GenresTable& value1, const GenresTable& value2) {
        return value1.GenresPlay > value2.GenresPlay;
    }

    vector<int> solution(vector<string> genres, vector<int> plays) {
        vector<int> answer;
        map<string, GenresTable> table;
        
        for (int i = 0; i < plays.size(); i++) {
            auto iter = table.find(genres[i]);
            SingInfo singInfo{ i,plays[i] };
            if (iter == table.end()) {
                GenresTable genresInfo{genres[i]};
                genresInfo.GenresPlay+=plays[i];
                genresInfo.sings.insert(singInfo);
                table.insert(make_pair(genres[i], genresInfo));
            }
            else {
                iter->second.GenresPlay+=plays[i];
                iter->second.sings.insert(singInfo);
            }
        }
        vector<GenresTable> genresVector;
        for (auto iter=table.begin(); iter != table.end(); iter++) {
            genresVector.push_back(iter->second);
        }
        sort(genresVector.begin(), genresVector.end(), GenresPlayCompare);
        for (auto element : genresVector) {
            int index = 0;
            for (auto it = element.sings.begin(); it != element.sings.end() && index < 2; it++, index++) {
                answer.push_back(it->id);
            }
        }
        return answer;
    }
}