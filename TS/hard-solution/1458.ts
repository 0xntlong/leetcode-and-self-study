/**
1458. Max Dot Product of Two Subsequences
    Given two arrays nums1 and nums2.
    Return the maximum dot product between non-empty subsequences of nums1 and nums2 with the same length.
    A subsequence of a array is a new array which is formed from the original array by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, [2,3,5] is a subsequence of [1,2,3,4,5] while [1,5,3] is not).

    Example :
    Input: nums1 = [2,1,-2,5], nums2 = [3,0,-6]
    Output: 18
    Explanation: Take subsequence [2,-2] from nums1 and subsequence [3,-6] from nums2.
    Their dot product is (2*3 + (-2)*(-6)) = 18.
 */



function maxDotProduct(nums1: number[], nums2: number[]): number {
    if (nums1[0] > nums2[0]) {
        const tmp = nums1; nums1 = nums2; nums2 = tmp;
    }

    const max1 = Math.max(...nums1);
    const min2 = Math.min(...nums2);
    if (max1 < 0 && min2 > 0) return max1 * min2;

    const m = nums1.length, n = nums2.length;
    const dp: number[] = new Array(n + 1).fill(0);

    for (let i = 0; i < m; i++) {
        for (let j = n - 1; j >= 0; j--) {
            const v = nums1[i] * nums2[j] + dp[j];
            if (v > dp[j + 1]) dp[j + 1] = v;
        }
        for (let j = 0; j < n; j++) {
            if (dp[j + 1] < dp[j]) dp[j + 1] = dp[j];
        }
    }

    return dp[n];
};