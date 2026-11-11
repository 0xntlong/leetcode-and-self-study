/**
3789. Minimum Cost to Acquire Required Items
    You are given five integers cost1, cost2, costBoth, need1, and need2.
    There are three types of items available:
    An item of type 1 costs cost1 and contributes 1 unit to the type 1 requirement only.
    An item of type 2 costs cost2 and contributes 1 unit to the type 2 requirement only.
    An item of type 3 costs costBoth and contributes 1 unit to both type 1 and type 2 requirements.
    You must collect enough items so that the total contribution toward type 1 is at least need1 and the total contribution toward type 2 is at least need2.
    Return an integer representing the minimum possible total cost to achieve these requirements.

    Example :
    Input: cost1 = 3, cost2 = 2, costBoth = 1, need1 = 3, need2 = 2
    Output: 3
    Explanation:
    After buying three type 3 items, which cost 3 * 1 = 3, the total contribution to type 1 is 3 (>= need1 = 3) and to type 2 is 3 (>= need2 = 2).
    Any other valid combination would cost more, so the minimum total cost is 3.
 */



/**
 * @param {number} cost1
 * @param {number} cost2
 * @param {number} costBoth
 * @param {number} need1
 * @param {number} need2
 * @return {number}
 */
var minimumCost = function(cost1, cost2, costBoth, need1, need2) {
    let totalCost = 0;

    if (cost1 + cost2 <= costBoth) {
        totalCost = cost1 * need1 + cost2 * need2;
    } else {
        const cnt_3 = Math.min(need1, need2);
        totalCost = cnt_3 * costBoth;

        need1 -= cnt_3;
        need2 -= cnt_3;

        if (need1 > 0) {
            totalCost += need1 * Math.min(cost1, costBoth);
        } else if (need2 > 0) {
            totalCost += need2 * Math.min(cost2, costBoth);
        }
    }

    return totalCost;
};