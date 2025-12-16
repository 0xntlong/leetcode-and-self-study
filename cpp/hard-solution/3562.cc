/**
3562. Maximum Profit from Trading Stocks with Discounts
    You are given an integer n, representing the number of employees in a company. Each employee is assigned a unique ID from 1 to n, and employee 1 is the CEO. You are given two 1-based integer arrays, present and future, each of length n, where:
    present[i] represents the current price at which the ith employee can buy a stock today.
    future[i] represents the expected price at which the ith employee can sell the stock tomorrow.
    The company's hierarchy is represented by a 2D integer array hierarchy, where hierarchy[i] = [ui, vi] means that employee ui is the direct boss of employee vi.
    Additionally, you have an integer budget representing the total funds available for investment.
    However, the company has a discount policy: if an employee's direct boss purchases their own stock, then the employee can buy their stock at half the original price (floor(present[v] / 2)).
    Return the maximum profit that can be achieved without exceeding the given budget.

    Note:
    You may buy each stock at most once.
    You cannot use any profit earned from future stock prices to fund additional investments and must buy only from budget.
    
    Example :
    Input: n = 2, present = [1,2], future = [4,3], hierarchy = [[1,2]], budget = 3

    Output: 5
    Explanation:


    Employee 1 buys the stock at price 1 and earns a profit of 4 - 1 = 3.
    Since Employee 1 is the direct boss of Employee 2, Employee 2 gets a discounted price of floor(2 / 2) = 1.
    Employee 2 buys the stock at price 1 and earns a profit of 3 - 1 = 2.
    The total buying cost is 1 + 1 = 2 <= budget. Thus, the maximum total profit achieved is 3 + 2 = 5.
 */



#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        vector<vector<int>> tree(n);
        vector<int> in_degree(n, 0);
        for (auto &e : hierarchy) {
            int u = e[0] - 1;
            int v = e[1] - 1;
            tree[u].push_back(v);
            in_degree[v]++;
        }
        int root = 0;
        for (int i = 0; i < n; i++) {
            if (in_degree[i] == 0) {
                root = i;
                break;
            }
        }
        const long long INF = -(long long)1e15;
        vector<int> capability(n, 0);
        function<long long(int)> cap = [&](int u) -> long long {
            long long s = present[u];
            for (int v : tree[u]) s += cap(v);
            capability[u] = (int)min<long long>(budget, s);
            return s;
        };
        cap(root);

        vector<vector<long long>> dp0(n), dp1(n);

        auto merge = [&](const vector<long long>& a, const vector<long long>& b) -> vector<long long> {
            int len_a = (int)a.size() - 1;
            int len_b = (int)b.size() - 1;
            int total = min(budget, len_a + len_b);

            vector<long long> c(total + 1, INF);

            for (int i = 0; i <= min(len_a, total); i++) {
                long long ai = a[i];
                if (ai == INF) 
                    continue;
                int maxj = min(len_b, total - i);
                for (int j = 0; j <= maxj; j++) {
                    long long bj = b[j];
                    if (bj == INF) 
                        continue;
                    long long val = ai + bj;
                    if (val > c[i + j]) c[i + j] = val;
                }
            }
            return c;
        };

        function<void(int)> dfs = [&](int u) {
            for (int v : tree[u]) 
                dfs(v);

            vector<long long> skip(capability[u] + 1, INF);
            vector<long long> base(capability[u] + 1, INF);
            skip[0] = 0;
            base[0] = 0;

            for (int v : tree[u]) {
                skip = merge(skip, dp0[v]);
                base = merge(base, dp1[v]);
            }

            auto comp = [&](int parentBought) -> vector<long long> {
                int price = parentBought ? (present[u] / 2) : present[u];
                long long profit = (long long)future[u] - price;
                vector<long long> maximize = skip; 
                if (price <= capability[u]) {
                    for (int b = price; b <= capability[u]; b++) {
                        if (base[b - price] != INF) {
                            long long can = base[b - price] + profit;
                            if (can > maximize[b]) 
                                maximize[b] = can;
                        }
                    }
                }
                return maximize;
            };

            dp0[u] = comp(0);
            dp1[u] = comp(1);
        };

        dfs(root);
        return *max_element(dp0[root].begin(), dp0[root].end());
    }
};