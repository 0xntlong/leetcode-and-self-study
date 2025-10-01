/**
1518. Water Bottles
    There are numBottles water bottles that are initially full of water. You can exchange numExchange empty water bottles from the market with one full water bottle.
    The operation of drinking a full water bottle turns it into an empty bottle.
    Given the two integers numBottles and numExchange, return the maximum number of water bottles you can drink.

    Example :
    Input: numBottles = 9, numExchange = 3
    Output: 13
    Explanation: You can exchange 3 empty bottles to get 1 full water bottle.
    Number of water bottles you can drink: 9 + 3 + 1 = 13.
 */



/**
 * @param {number} numBottles
 * @param {number} numExchange
 * @return {number}
 */
var numWaterBottles = function(numBottles, numExchange) {
    let drinked = 0;
    let empty = 0;
    while (numBottles > 0){
        drinked += numBottles;
        empty += numBottles;
        let n = Math.floor(empty / numExchange);
        numBottles = n;
        empty -= n * numExchange;
    }
    return drinked;
};