/**
1390. Four Divisors
    Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors. If there is no such integer in the array, return 0.
    Example :
    Input: nums = [21,4,7]
    Output: 32
    Explanation: 
    21 has 4 divisors: 1, 3, 7, 21
    4 has 3 divisors: 1, 2, 4
    7 has 2 divisors: 1, 7
    The answer is the sum of divisors of 21 only.
 */



/**
 * @param {number[]} nums
 * @return {number}
 */
var sumFourDivisors = function(nums) {
    const divSumFour = (n) => {
        let sum = 0, cnt = 0;
        for (let i = 1; i * i <= n; i++) {
            if (n % i !== 0) 
                continue;
            cnt++;
            sum += i;
            const other = Math.floor(n / i);
            if (other !== i) {
                cnt++;
                sum += other;
            }
            if (cnt > 4) 
                return 0;
        }
        return cnt === 4 ? sum : 0;
    };

    let res = 0;
    for (const n of nums) {
        res += divSumFour(n);
    }
    return res;
};