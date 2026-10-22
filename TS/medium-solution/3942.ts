/**
3942. Minimum Operations to Sort a Permutation
    You are given an integer array nums of length n, where nums is a permutation of the integers from 0 to n - 1.
    You may perform only the following operations:
    Reverse the entire array.
    Rotate Left by One: Move the first element to the end of the array, and rest elements to left by one position.
    Return an integer denoting the minimum number of operations required to sort the array in increasing order. If it is not possible to sort the array using only the given operations, return -1.
    Example :
    Input: nums = [0,2,1]
    Output: 2
    Explanation:
    Rotate Left by one: [2, 1, 0]
    Reverse the array: [0, 1, 2]
    The array becomes sorted in 2 operations, which is minimal
 */



function minOperations(nums: number[]): number {
    const n = nums.length;

    if (n === 0) {
        return -1;
    }

    let res: number = Infinity;

    const target: number[] = Array.from(
        { length: n },
        (_, i) => i
    );

    const k: number = nums.indexOf(0);

    if (k === -1) {
        return -1;
    }

    const rotated: number[] = nums.slice(k).concat(
        nums.slice(0, k)
    );

    if (rotated.every((value, i) => value === target[i])) {
        res = Math.min(res, k, n - k + 2);
    }

    const revNums: number[] = [...nums].reverse();
    const kRev: number = revNums.indexOf(0);

    const revRotated: number[] = revNums.slice(kRev).concat(
        revNums.slice(0, kRev)
    );

    if (revRotated.every((value, i) => value === target[i])) {
        res = Math.min(res, kRev + 1, n - kRev + 1);
    }

    return res === Infinity ? -1 : res;
};