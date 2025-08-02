/**
2561. Rearranging Fruits 
    You have two fruit baskets containing n fruits each. You are given two 0-indexed integer arrays basket1 and basket2 representing the cost of fruit in each basket. You want to make both baskets equal. To do so, you can use the following operation as many times as you want:

    Chose two indices i and j, and swap the ith fruit of basket1 with the jth fruit of basket2.
    The cost of the swap is min(basket1[i],basket2[j]).
    Two baskets are considered equal if sorting them according to the fruit cost makes them exactly the same baskets.

    Return the minimum cost to make both the baskets equal or -1 if impossible.

    Example :

    Input: basket1 = [4,2,2,2], basket2 = [1,4,1,2]
    Output: 1
    Explanation: Swap index 1 of basket1 with index 0 of basket2, which has cost 1. Now basket1 = [4,1,2,2] and basket2 = [2,4,1,2]. Rearranging both the arrays makes them equal.
 */




/**
 * @param {number[]} basket1
 * @param {number[]} basket2
 * @return {number}
 */
var minCost = function(basket1, basket2) {
    const count1 = new Map();
    const count2 = new Map();
    let minX = Infinity;
    for (const x of basket1){
        count1.set(x, (count1.get(x) || 0) + 1)
        minX = Math.min(minX, x);
    }
    for (const x of basket2){
        count2.set(x, (count2.get(x) || 0) + 1)
        minX = Math.min(minX, x);
    }
    for (const [key, val1] of count1.entries()) {
        const val2 = count2.get(key) || 0;
        const minCount = Math.min(val1, val2);
        count1.set(key, val1 - minCount);
        count2.set(key, val2 - minCount);
    }
    const swap1 = [], swap2 = [];
    for (const [key, val] of count1.entries()){
        if (val % 2 !== 0){
            return -1;
        }
        for (let i = 0; i < val / 2; i++){
            swap1.push(key);
        }
    }
    for (const [key, val] of count2.entries()){
        if (val % 2 !== 0){
            return -1;
        }
        for (let i = 0; i < val / 2; i++){
            swap2.push(key);
        }
    }
    swap1.sort((a, b) => a - b);
    swap2.sort((a, b) => b - a);
    let res = 0; 
    for (let i = 0; i < swap1.length; i++){
        res += Math.min(swap1[i], swap2[i], 2 * minX);
    }
    return res;
};