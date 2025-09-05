/**
2749. Minimum Operations to Make the Integer Zero
    You are given two integers num1 and num2.
    In one operation, you can choose integer i in the range [0, 60] and subtract 2i + num2 from num1.
    Return the integer denoting the minimum number of operations needed to make num1 equal to 0.
    If it is impossible to make num1 equal to 0, return -1.

    Example :
    Input: num1 = 3, num2 = -2
    Output: 3
    Explanation: We can make 3 equal to 0 with the following operations:
    - We choose i = 2 and subtract 22 + (-2) from 3, 3 - (4 + (-2)) = 1.
    - We choose i = 2 and subtract 22 + (-2) from 1, 1 - (4 + (-2)) = -1.
    - We choose i = 0 and subtract 20 + (-2) from -1, (-1) - (1 + (-2)) = 0.
    It can be proven, that 3 is the minimum number of operations that we need to perform.
 */




/**
 * @param {number} num1
 * @param {number} num2
 * @return {number}
 */
var makeTheIntegerZero = function(num1, num2) {
    let k = 1; 
    while (true){
        let x = BigInt(num1) - BigInt(num2) * BigInt(k);
        if (x < BigInt(k)){
            return -1;
        }
        if (k >= bitCount(x)){
            return k;
        }
        k++;
    }
};
function bitCount(n){
    let count = 0;
    while (n !== 0n){
        count++;
        n &= n - 1n;
    }
    return count;
}