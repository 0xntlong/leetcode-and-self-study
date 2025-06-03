/**
1298. Maximum Candies You Can Get from Boxes
    You have n boxes labeled from 0 to n - 1. You are given four arrays: status, candies, keys, and containedBoxes where:
    status[i] is 1 if the ith box is open and 0 if the ith box is closed,
    candies[i] is the number of candies in the ith box,
    keys[i] is a list of the labels of the boxes you can open after opening the ith box.
    containedBoxes[i] is a list of the boxes you found inside the ith box.
    You are given an integer array initialBoxes that contains the labels of the boxes you initially have. You can take all the candies in any open box and you can use the keys in it to open new boxes and you also can use the boxes you find in it.
    Return the maximum number of candies you can get following the rules above.

    Example :
    Input: status = [1,0,1,0], candies = [7,5,4,100], keys = [[],[],[1],[]], containedBoxes = [[1,2],[3],[],[]], initialBoxes = [0]
    Output: 16
    Explanation: You will be initially given box 0. You will find 7 candies in it and boxes 1 and 2.
    Box 1 is closed and you do not have a key for it so you will open box 2. You will find 4 candies and a key to box 1 in box 2.
    In box 1, you will find 5 candies and box 3 but you will not find a key to box 3 so box 3 will remain closed.
    Total number of candies collected = 7 + 4 + 5 = 16 candy.
 */



/**
 * @param {number[]} status
 * @param {number[]} candies
 * @param {number[][]} keys
 * @param {number[][]} containedBoxes
 * @param {number[]} initialBoxes
 * @return {number}
 */
var maxCandies = function(status, candies, keys, containedBoxes, initialBoxes) {
    let cnt = 0;
    let q = [...initialBoxes];
    while (q.length > 0){
        const sz = q.length;
        const curr = [];
        const inserted = [];
        for (let i = 0; i < sz; i++){
            const box = q.shift();
            curr.push(box);
            if (status[box] === 1){
                cnt += candies[box];
                for (const k of keys[box]){
                    status[k] = 1;
                }
                for (const other of containedBoxes[box]){
                    q.push(other);
                }
            } else {
                q.push(box);
                inserted.push(box);
            }
        }
        if (curr.length === inserted.length && curr.every((v, idx) => v === inserted[idx])){
            break;
        }
    }
    return cnt;
};