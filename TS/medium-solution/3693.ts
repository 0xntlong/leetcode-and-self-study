/**
3693. Climbing Stairs II
    You are climbing a staircase with n + 1 steps, numbered from 0 to n.
    You are also given a 1-indexed integer array costs of length n, where costs[i] is the cost of step i.
    From step i, you can jump only to step i + 1, i + 2, or i + 3. The cost of jumping from step i to step j is defined as: costs[j] + (j - i)2
    You start from step 0 with cost = 0.
    Return the minimum total cost to reach step n.

    Example :
    Input: n = 4, costs = [1,2,3,4]
    Output: 13
    Explanation:
    One optimal path is 0 → 1 → 2 → 4
    Jump	Cost Calculation	Cost
    0 → 1	costs[1] + (1 - 0)2 = 1 + 1	2
    1 → 2	costs[2] + (2 - 1)2 = 2 + 1	3
    2 → 4	costs[4] + (4 - 2)2 = 4 + 4	8
    Thus, the minimum total cost is 2 + 3 + 8 = 13
 */



function climbStairs(n: number, costs: number[]): number {
    let f0 = 0, f1 = 0, f2 = 0;

    for (const c of costs) {
        [f0, f1, f2] = [
            f1,
            f2,
            Math.min(f0 + 9, f1 + 4, f2 + 1) + c
        ];
    }

    return f2;
};