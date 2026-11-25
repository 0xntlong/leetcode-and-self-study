/**
3934. Smallest Unique Subarray
    You are given an integer array nums.
    Find the minimum length of a subarray that is not identical to any other subarray in nums.
    Return an integer denoting the minimum possible length of such a subarray.
    Two subarrays are considered identical if they have the same length and the same elements in corresponding positions.

    Example :
    Input: nums = [3,3,3]
    Output: 3
    Explanation:
    Subarrays of length 1: [3] → appears 3 times
    Subarrays of length 2: [3, 3] → appears 2 times
    Subarrays of length 3: [3, 3, 3] → appears once
    The subarray [3, 3, 3] is unique, so the smallest unique subarray length is 3.
 */



function smallestUniqueSubarray(nums: number[]): number {
    let low = 1;
    let high = nums.length + 1;
    let ans = -1;

    const base = 100003n;
    const modulus = 1000000007n;

    const modPow = (
        base: bigint,
        exp: number,
        modulus: bigint
    ): bigint => {
        let res = 1n;

        while (exp > 0) {
            if (exp & 1) {
                res = res * base % modulus;
            }
            base = base * base % modulus;
            exp = Math.floor(exp / 2);
        }

        return res;
    };

    while (low < high) {
        const mid = low + Math.floor((high - low) / 2);

        const unique = new Set<bigint>();
        const non_unique = new Set<bigint>();

        let subarray = 0n;
        const pow1 = modPow(base, mid - 1, modulus);

        for (let i = 0; i + mid <= nums.length; i++) {
            if (i === 0) {
                for (let j = i; j < i + mid; j++) {
                    subarray = (subarray * base + BigInt(nums[j])) % modulus;
                }
            } else {
                subarray = (subarray - BigInt(nums[i - 1]) * pow1 % modulus + modulus) % modulus;
                subarray = (subarray * base + BigInt(nums[i + mid - 1])) % modulus;
            }

            if (non_unique.has(subarray)) {
                continue;
            } else if (unique.has(subarray)) {
                unique.delete(subarray);
                non_unique.add(subarray);
            } else {
                unique.add(subarray);
            }
        }

        if (unique.size > 0) {
            high = mid;
            ans = mid;
        } else {
            low = mid + 1;
        }
    }

    return ans;
};