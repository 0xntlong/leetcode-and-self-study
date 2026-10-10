/**
2333. Minimum Sum of Squared Difference
    You are given two positive 0-indexed integer arrays nums1 and nums2, both of length n.
    The sum of squared difference of arrays nums1 and nums2 is defined as the sum of (nums1[i] - nums2[i])2 for each 0 <= i < n.
    You are also given two positive integers k1 and k2. You can modify any of the elements of nums1 by +1 or -1 at most k1 times. Similarly, you can modify any of the elements of nums2 by +1 or -1 at most k2 times.
    Return the minimum sum of squared difference after modifying array nums1 at most k1 times and modifying array nums2 at most k2 times.
    Note: You are allowed to modify the array elements to become negative integers.

    Example :
    Input: nums1 = [1,2,3,4], nums2 = [2,10,20,19], k1 = 0, k2 = 0
    Output: 579
    Explanation: The elements in nums1 and nums2 cannot be modified because k1 = 0 and k2 = 0. 
    The sum of square difference will be: (1 - 2)2 + (2 - 10)2 + (3 - 20)2 + (4 - 19)2 = 579.
 */



class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        int n = nums1.size();
        vector<long long> d(n);

        long long total = 0;

        for (int i = 0; i < n; i++) {
            d[i] = abs(nums1[i] - nums2[i]);
            total += d[i];
        }

        if (total <= k)
            return 0;

        sort(d.rbegin(), d.rend());
        d.push_back(0);

        for (int i = 1; i <= n; i++) {
            long long cost = (d[i - 1] - d[i]) * i;

            if (cost > k) {
                long long q = k / i;
                long long r = k % i;
                long long hi = d[i - 1] - q;

                long long res = hi * hi * (i - r)
                              + (hi - 1) * (hi - 1) * r;

                for (int j = i; j < n; j++)
                    res += d[j] * d[j];

                return res;
            }

            k -= cost;
        }

        return 0;
    }
};