/**
2197. Replace Non-Coprime Numbers in Array
    You are given an array of integers nums. Perform the following steps:
    Find any two adjacent numbers in nums that are non-coprime.
    If no such numbers are found, stop the process.
    Otherwise, delete the two numbers and replace them with their LCM (Least Common Multiple).
    Repeat this process as long as you keep finding two adjacent non-coprime numbers.
    Return the final modified array. It can be shown that replacing adjacent non-coprime numbers in any arbitrary order will lead to the same result.
    The test cases are generated such that the values in the final array are less than or equal to 108.
    Two values x and y are non-coprime if GCD(x, y) > 1 where GCD(x, y) is the Greatest Common Divisor of x and y
    
    Example :
    Input: nums = [6,4,3,2,7,6,2]
    Output: [12,7,6]
    Explanation: 
    - (6, 4) are non-coprime with LCM(6, 4) = 12. Now, nums = [12,3,2,7,6,2].
    - (12, 3) are non-coprime with LCM(12, 3) = 12. Now, nums = [12,2,7,6,2].
    - (12, 2) are non-coprime with LCM(12, 2) = 12. Now, nums = [12,7,6,2].
    - (6, 2) are non-coprime with LCM(6, 2) = 6. Now, nums = [12,7,6].
    There are no more adjacent non-coprime numbers in nums.
    Thus, the final modified array is [12,7,6].
    Note that there are other ways to obtain the same resultant array.
 */





/**
 * @param {number[]} nums
 * @return {number[]}
 */
var replaceNonCoprimes = function(nums) {
    const st = [];
    const gcd = (a, b) => {
        while (b !== 0n){
            const t = a % b;
            a = b;
            b = t;
        }
        return a;
    };
    for (const i of nums){
        st.push(BigInt(i));
        while (st.length > 1){
            const a = st.pop();
            const b = st.pop();
            const g = gcd(a, b);
            if (g == 1n){
                st.push(b, a);
                break;
            } else {
                st.push((a / g) * b);
            }
        }
    }
    return st.map(v => Number(v));
};