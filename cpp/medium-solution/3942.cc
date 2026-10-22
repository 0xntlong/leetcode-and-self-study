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



class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) {
            return -1;
        }

        int res = INT_MAX;
        vector<int> target(n);
        iota(target.begin(), target.end(), 0);

        auto it = find(nums.begin(), nums.end(), 0);
        if (it == nums.end()) return -1;

        int k = it - nums.begin();

        vector<int> rotated;
        rotated.insert(rotated.end(), nums.begin() + k, nums.end());
        rotated.insert(rotated.end(), nums.begin(), nums.begin() + k);

        if (rotated == target) {
            res = min({res, k, n - k + 2});
        }

        vector<int> rev_nums(nums.rbegin(), nums.rend());

        auto rev_it = find(rev_nums.begin(), rev_nums.end(), 0);
        int k_rev = rev_it - rev_nums.begin();

        rotated.clear();
        rotated.insert(rotated.end(), rev_nums.begin() + k_rev, rev_nums.end());
        rotated.insert(rotated.end(), rev_nums.begin(), rev_nums.begin() + k_rev);

        if (rotated == target) {
            res = min({res, k_rev + 1, n - k_rev + 1});
        }

        return res == INT_MAX ? -1 : res;
    }
};