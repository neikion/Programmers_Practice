//https://school.programmers.co.kr/learn/courses/30/lessons/86971

#include <string>
#include <vector>
// 다른 사람의 풀이1 에서 필요.
// #include<functional>

namespace ElectricGrid {
    using namespace std;
    class node {
    public:
        int value;
        int NodeCount = 1;
        vector<node> child;
        node(int value) : value(value) {};

        bool push(vector<int> ivalue) {
            if (ivalue[0] == this->value) {
                child.push_back(node{ ivalue[1] });
                NodeCount++;
                return true;
            }
            else if (ivalue[1] == this->value) {
                child.push_back(node{ ivalue[0] });
                NodeCount++;
                return true;
            }
            for (int index=0; index < child.size(); index++) {
                if (child[index].push(ivalue)) {
                    NodeCount++;
                    return true;
                }
            }
            return false;
        }

        int find(int allNodeCount,int min) {
            int temp=0;
            if (NodeCount == 1) {
                return allNodeCount;
            }
            for (int index = 0; index < child.size(); index++) {
                temp = child[index].find(allNodeCount,min);
                if (temp < min) {
                    min = temp;
                }
            }
            for (int i = 0; i < child.size(); i++) {
                temp = abs(allNodeCount - (child[i].NodeCount*2));
                if (temp < min) {
                    min = temp;
                }
            }
            return min;
        }
    };

    int solution(int n, vector<vector<int>> wires) {
        node root{wires[0][0]};
        root.child.push_back(node(wires[0][1]));
        root.NodeCount++;
        wires.erase(wires.begin());
        int index = 0;
        while (wires.size() > 0) {
            if (index >= wires.size()) {
                index = 0;
            }
            if (root.push(wires[index])) {
                wires.erase(wires.begin() + index);
                continue;
            }
            index++;
        }
        return root.find(root.NodeCount, 100);
    }

    /* 다른 사람의 풀이 1
    int solution2(int n, vector<vector<int>> wires) {
        //각 노드마다 연결 리스트 생성
        vector<vector<int>> graph(n + 1);
        for (int i = 0; i < (int)wires.size(); i++) {
            int u = wires[i][0];
            int v = wires[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        //자기 자신을 포함한 연결된 하위노드 수를 기록한 리스트
        vector<int> siz(n + 1);

        function<void(int, int)> dfs = [&](int cur, int prev)  -> void {
            //탐색 노드에 자기 자신을 연결한 노드로 표시
            //다음에 탐색할 노드가 없다면 이 코드만 실행하고 종료됨.
            siz[cur] = 1;
            cout << "current " << cur << endl;
            for (int nxt : graph[cur]) {
                //자신이 왔던 이전 노드라면 다음 노드를 탐색
                if (nxt == prev) continue;
                //다음 노드에서 연결된 노드 먼저 탐색
                dfs(nxt, cur);
                //더 이상 탐색할 노드가 없다면 아레 코드로 오게됨.
                //현재 노드에 다음 노드의 연결 노드들 수를 추가하여 기록
                siz[cur] += siz[nxt];
            }
            };
        dfs(1, -1);
        int answer = INT_MAX;
        //각 노드의 자기 자신을 포함한 연결노드의 수를 통해
        //선택 노드의 연결 노드 수와 나머지 노드 수의 수를 비교.
        for (int i = 1; i <= n; i++) {
            for (int j : graph[i]) {
                int l = siz[j];
                int r = n - siz[j];
                answer = min(answer, abs(l - r));
            }
        }
        return answer;
    }
    */
}