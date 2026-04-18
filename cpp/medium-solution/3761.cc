/**
 * 3761. Minimum Absolute Distance Between Mirror Pairs
    You are given an integer array nums.

    A mirror pair is a pair of indices (i, j) such that:

    0 <= i < j < nums.length, and
    reverse(nums[i]) == nums[j], where reverse(x) denotes the integer formed by reversing the digits of x. Leading zeros are omitted after reversing, for example reverse(120) = 21.
    Return the minimum absolute distance between the indices of any mirror pair. The absolute distance between indices i and j is abs(i - j).

    If no mirror pair exists, return -1.

    

    Example 1:

    Input: nums = [12,21,45,33,54]

    Output: 1

    Explanation:

    The mirror pairs are:

    (0, 1) since reverse(nums[0]) = reverse(12) = 21 = nums[1], giving an absolute distance abs(0 - 1) = 1.
    (2, 4) since reverse(nums[2]) = reverse(45) = 54 = nums[4], giving an absolute distance abs(2 - 4) = 2.
    The minimum absolute distance among all pairs is 1.
 */

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reverseNum(int num) {
        int rev = 0;
        while (num > 0) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int mini = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (mp.count(num)) {
                mini = min(mini, i - mp[num]);
            }
            int rev = reverseNum(num);
            mp[rev] = i;
        }

        return mini == INT_MAX ? -1 : mini;
    }
};