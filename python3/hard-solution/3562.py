"""
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
"""


from typing import List

class Solution:
    def maxProfit(self, n: int, present: List[int], future: List[int], hierarchy: List[List[int]], budget: int) -> int:
        tree = [[] for _ in range(n)]
        in_degree = [0] * n
        for u, v in hierarchy:
            u -= 1
            v -= 1
            tree[u].append(v)
            in_degree[v] += 1
        root = 0
        for i in range(n):
            if in_degree[i] == 0:
                root = i
                break
        INF = -10 ** 15
        capability = [0] * n
        def cap(u):
            s = present[u]
            for v in tree[u]:
                s += cap(v)
            capability[u] = min(budget, s)
            return s
        cap(root)
        dp0 = [None] * n
        dp1 = [None] * n
        def merge(a, b):
            len_a = len(a) - 1
            len_b = len(b) - 1
            total = min(budget, len_a + len_b)
            c = [INF] * (total + 1)
            for i in range(min(len_a, total) + 1):
                ai = a[i]
                if ai == INF:
                    continue
                maxj = min(len_b, total - i)
                for j in range(maxj + 1):
                    bj = b[j]
                    if bj == INF:
                        continue
                    val = ai + bj
                    if val > c[i + j]:
                        c[i + j] = val
            return c
        def dfs(u):
            for v in tree[u]:
                dfs(v)
            skip = [INF] * (capability[u] + 1)
            skip[0] = 0
            base = [INF] * (capability[u] + 1)
            base[0] = 0
            for v in tree[u]:
                skip = merge(skip, dp0[v])
                base = merge(base, dp1[v])
            def comp(p):
                price = present[u] // 2 if p else present[u]
                profit = future[u] - price
                maximize = skip[:]
                if price <= capability[u]:
                    for b in range(price, capability[u] + 1):
                        if base[b - price] != INF:
                            can = base[b - price] + profit
                            if can > maximize[b]:
                                maximize[b] = can
                return maximize
            dp0[u] = comp(0)
            dp1[u] = comp(1)
        dfs(root)
        return max(dp0[root])