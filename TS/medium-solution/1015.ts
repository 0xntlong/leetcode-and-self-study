/**
1015. Smallest Integer Divisible by K
    Given a positive integer k, you need to find the length of the smallest positive integer n such that n is divisible by k, and n only contains the digit 1.
    Return the length of n. If there is no such n, return -1.
    Note: n may not fit in a 64-bit signed integer.

    Example :
    Input: k = 1
    Output: 1
    Explanation: The smallest answer is n = 1, which has length 1.
 */

 
function smallestRepunitDivByK(k: number): number {
    if (k % 2 === 0 || k % 5 === 0){
        return -1;
    }
    let remain = 0;
    let l = 0;
    for (let i = 1; i <= k; i++){
        remain = (remain * 10 + 1) % k;
        l++;
        if (remain === 0){
            return l;
        }
    }
    return l;
};