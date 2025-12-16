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




function maxProfit(n: number, present: number[], future: number[], hierarchy: number[][], budget: number): number {
    const INF = -1e15;
    const tree: number[][] = Array.from({ length: n }, () => []);
    const indeg = Array(n).fill(0);

    for (const [u, v] of hierarchy) {
        tree[u - 1].push(v - 1);
        indeg[v - 1]++;
    }

    const root = indeg.findIndex(x => x === 0);
    const capability = Array(n).fill(0);

    function cap(u: number): number {
        let sum = present[u];
        for (const v of tree[u]) sum += cap(v);
        capability[u] = Math.min(budget, sum);
        return sum;
    }

    cap(root);

    function merge(a: number[], b: number[]): number[] {
        const total = Math.min(budget, a.length + b.length - 2);
        const c = Array(total + 1).fill(INF);

        for (let i = 0; i < a.length; i++) {
            if (a[i] === INF) 
                continue;
            for (let j = 0; j < b.length && i + j <= total; j++) {
                if (b[j] === INF) 
                    continue;
                c[i + j] = Math.max(c[i + j], a[i] + b[j]);
            }
        }
        return c;
    }

    const dp0: number[][] = Array(n);
    const dp1: number[][] = Array(n);

    function dfs(u: number): void {
        for (const v of tree[u]) 
            dfs(v);

        let skip = Array(capability[u] + 1).fill(INF);
        let base = Array(capability[u] + 1).fill(INF);
        skip[0] = base[0] = 0;

        for (const v of tree[u]) {
            skip = merge(skip, dp0[v]);
            base = merge(base, dp1[v]);
        }

        function compute(parentBought: number): number[] {
            const price = parentBought ? Math.floor(present[u] / 2) : present[u];
            const profit = future[u] - price;
            const res = [...skip];
            for (let b = price; b < res.length; b++) {
                if (base[b - price] !== INF) {
                    res[b] = Math.max(res[b], base[b - price] + profit);
                }
            }
            return res;
        }

        dp0[u] = compute(0);
        dp1[u] = compute(1);
    }

    dfs(root);
    return Math.max(...dp0[root]);
};