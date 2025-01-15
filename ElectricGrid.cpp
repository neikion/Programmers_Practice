//https://school.programmers.co.kr/learn/courses/30/lessons/86971

#include <string>
#include <vector>
// �ٸ� ����� Ǯ��1 ���� �ʿ�.
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

    /* �ٸ� ����� Ǯ�� 1
    int solution2(int n, vector<vector<int>> wires) {
        //�� ��帶�� ���� ����Ʈ ����
        vector<vector<int>> graph(n + 1);
        for (int i = 0; i < (int)wires.size(); i++) {
            int u = wires[i][0];
            int v = wires[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        //�ڱ� �ڽ��� ������ ����� ������� ���� ����� ����Ʈ
        vector<int> siz(n + 1);

        function<void(int, int)> dfs = [&](int cur, int prev)  -> void {
            //Ž�� ��忡 �ڱ� �ڽ��� ������ ���� ǥ��
            //������ Ž���� ��尡 ���ٸ� �� �ڵ常 �����ϰ� �����.
            siz[cur] = 1;
            cout << "current " << cur << endl;
            for (int nxt : graph[cur]) {
                //�ڽ��� �Դ� ���� ����� ���� ��带 Ž��
                if (nxt == prev) continue;
                //���� ��忡�� ����� ��� ���� Ž��
                dfs(nxt, cur);
                //�� �̻� Ž���� ��尡 ���ٸ� �Ʒ� �ڵ�� ���Ե�.
                //���� ��忡 ���� ����� ���� ���� ���� �߰��Ͽ� ���
                siz[cur] += siz[nxt];
            }
            };
        dfs(1, -1);
        int answer = INT_MAX;
        //�� ����� �ڱ� �ڽ��� ������ �������� ���� ����
        //���� ����� ���� ��� ���� ������ ��� ���� ���� ��.
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