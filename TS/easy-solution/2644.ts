/**
2644. Find the Maximum Divisibility Score
    You are given two integer arrays nums and divisors.
    The divisibility score of divisors[i] is the number of indices j such that nums[j] is divisible by divisors[i].
    Return the integer divisors[i] with the maximum divisibility score. If multiple integers have the maximum score, return the smallest one.
    Example :
    Input: nums = [2,9,15,50], divisors = [5,3,7,2]
    Output: 2
    Explanation:
    The divisibility score of divisors[0] is 2 since nums[2] and nums[3] are divisible by 5.
    The divisibility score of divisors[1] is 2 since nums[1] and nums[2] are divisible by 3.
    The divisibility score of divisors[2] is 0 since none of the numbers in nums is divisible by 7.
    The divisibility score of divisors[3] is 2 since nums[0] and nums[3] are divisible by 2.
    As divisors[0], divisors[1], and divisors[3] have the same divisibility score, we return the smaller one which is divisors[3].
 */


function maxDivScore(nums: number[], divisors: number[]): number {
    let res : number = -1;
    let maxCnt : number = -1;
    for (let d of divisors){
        let cnt : number = 0;
        for (let i of nums){
            if (i % d === 0){
                cnt++;
            }
        }
        if (cnt > maxCnt){
            maxCnt = cnt;
            res = d;
        } else if (cnt === maxCnt){
            res = Math.min(res, d);
        }
    }
    return res;
};