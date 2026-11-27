/**
3946. Maximum Number of Items From Sale I
    You are given a 2D integer array items, where items[i] = [factori, pricei] represents the ith item. You are also given an integer budget.
    There are unlimited copies of each item available for purchase.You may buy any number of copies of any items such that the total cost of the purchased copies is at most budget.
    After buying items, you may receive free copies according to the following rules:
    For each item i that you bought at least one copy of, you receive one free copy of every item j such that j != i and factori divides factorj.
    Buying multiple copies of the same item i does not give additional free copies through item i.
    The same item j can be received multiple times for free if it is received from purchases of different item types.
    Return the maximum total number of item copies you can obtain, including both purchased copies and free copies, while spending at most budget on purchased items.

    Example :
    Input: items = [[6,2],[2,6],[3,4]], budget = 9
    Output: 4
    Explanation:
    You can buy 2 copies of item 0 and 1 copy of item 2 for a total cost of 2 * 2 + 4 = 8, which is not greater than budget = 9.
    Buying item 2 gives 1 free copy of item 0, because factor2 = 3 divides factor0 = 6.
    You leave with 3 purchased copies and 1 free copy, for a total of 4 item copies.
 */



/**
 * @param {number[][]} items
 * @param {number} budget
 * @return {number}
 */
var maximumSaleItems = function(items, budget) {
    const f = new Array(budget + 1).fill(0);
    let mn = Infinity;

    for (const [factor, price] of items) {
        mn = Math.min(mn, price);

        let cnt = 0;

        for (const [factor_j] of items) {
            if (factor_j % factor === 0) {
                cnt++;
            }
        }

        for (let j = budget; j >= price; j--) {
            f[j] = Math.max(f[j], f[j - price] + cnt);
        }
    }

    let ans = 0;

    for (let i = 0; i <= budget; i++) {
        ans = Math.max(ans, f[i] + Math.floor((budget - i) / mn));
    }

    return ans;
};