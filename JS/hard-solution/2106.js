/**
2106. Maximum Fruits Harvested After at Most K Steps   
    Fruits are available at some positions on an infinite x-axis. You are given a 2D integer array fruits where fruits[i] = [positioni, amounti] depicts amounti fruits at the position positioni. fruits is already sorted by positioni in ascending order, and each positioni is unique.
    You are also given an integer startPos and an integer k. Initially, you are at the position startPos. From any position, you can either walk to the left or right. It takes one step to move one unit on the x-axis, and you can walk at most k steps in total. For every position you reach, you harvest all the fruits at that position, and the fruits will disappear from that position.
    Return the maximum total number of fruits you can harvest.

    Example :
    Input: fruits = [[2,8],[6,3],[8,6]], startPos = 5, k = 4
    Output: 9
    Explanation: 
    The optimal way is to:
    - Move right to position 6 and harvest 3 fruits
    - Move right to position 8 and harvest 6 fruits
    You moved 3 steps and harvested 3 + 6 = 9 fruits in total.
 */



/**
 * @param {number[][]} fruits
 * @param {number} startPos
 * @param {number} k
 * @return {number}
 */
var maxTotalFruits = function(fruits, startPos, k) {
    const n = fruits.length;
    let res = 0; currSum = 0;
    const lowerBound = (target) => {
        let low = 0, high = n;
        while (low < high){
            let mid = (low + high) >> 1;
            if (fruits[mid][0] < target)
                low = mid + 1;
            else high = mid;
        }
        return low;
    };
    const upperBound = (target) => {
        let low = 0, high = n;
        while (low < high){
            let mid = (low + hight) >> 1;
            if (fruits[mid][0] <= target)
                low = mid + 1;
            else high = mid;
        }
        return low;
    };
    let left = lowerBound(startPos - k);
    let right = lowerBound(startPos);
    for (let i = left; i < right; i++) {
        currSum += fruits[i][1];
    }
    res = currSum;
    for (let i = right; i < n; i++){
        currSum += fruits[i][1];
        const r = fruits[i][0];
        if (r - startPos > k)
            break;
        while (left <= i && Math.min(Math.abs(r - startPos), Math.abs(startPos - fruits[left][0])) + (r - fruits[left][0]) > k){
            currSum -= fruits[left][1];
            left++;
        }
        res = Math.max(res, currSum);
    }
    return res;
};