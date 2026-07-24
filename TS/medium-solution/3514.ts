/**
3514. Number of Unique XOR Triplets II
    You are given an integer array nums.
    A XOR triplet is defined as the XOR of three elements nums[i] XOR nums[j] XOR nums[k] where i <= j <= k.
    Return the number of unique XOR triplet values from all possible triplets (i, j, k).
    Example :
    Input: nums = [1,3]
    Output: 2
    Explanation:
    The possible XOR triplet values are:
    (0, 0, 0) → 1 XOR 1 XOR 1 = 1
    (0, 0, 1) → 1 XOR 1 XOR 3 = 3
    (0, 1, 1) → 1 XOR 3 XOR 3 = 1
    (1, 1, 1) → 3 XOR 3 XOR 3 = 3
    The unique XOR values are {1, 3}. Thus, the output is 2.
 */


function uniqueXorTriplets(nums: number[]): number {
    const m = Math.max(...nums);

    let size = 1;

    while (size <= m) {
        size <<= 1;
    }

    const one: boolean[] = Array(size).fill(false);
    const two: boolean[] = Array(size).fill(false);
    const three: boolean[] = Array(size).fill(false);

    for (const x of nums) {
        one[x] = true;

        for (let y = 0; y < size; y++) {
            if (one[y]) {
                two[y ^ x] = true;
            }
        }
    }

    for (const x of nums) {
        for (let y = 0; y < size; y++) {
            if (two[y]) {
                three[y ^ x] = true;
            }
        }
    }

    let result = 0;

    for (const value of three) {
        if (value) {
            result++;
        }
    }

    return result;
}