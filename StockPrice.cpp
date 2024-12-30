//https://school.programmers.co.kr/learn/courses/30/lessons/42584/solution_groups?language=cpp

#include <string>
#include <vector>
#include <stack>

namespace StockPrice {
    using namespace std;
    vector<int> solution(vector<int> prices) {
        vector<int> answer(prices.size());
        stack<pair<int, int>> stock;
        for (int i = 0; i < prices.size(); i++) {
            while (stock.size() > 0 && stock.top().first > prices[i]) {
                auto p = stock.top();
                answer[p.second] = i - p.second;
                stock.pop();
            }
            answer[i] = prices.size() - i - 1;
            stock.push(make_pair(prices[i], i));
        }
        return answer;
    }
}