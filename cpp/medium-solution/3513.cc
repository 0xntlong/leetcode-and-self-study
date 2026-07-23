/**
3513. Number of Unique XOR Triplets I
    You are given an integer array nums of length n, where nums is a permutation of the numbers in the range [1, n].
    A XOR triplet is defined as the XOR of three elements nums[i] XOR nums[j] XOR nums[k] where i <= j <= k.
    Return the number of unique XOR triplet values from all possible triplets (i, j, k).

    Example 1:
    Input: nums = [1,2]
    Output: 2
    Explanation:
    The possible XOR triplet values are:
    (0, 0, 0) → 1 XOR 1 XOR 1 = 1
    (0, 0, 1) → 1 XOR 1 XOR 2 = 2
    (0, 1, 1) → 1 XOR 2 XOR 2 = 1
    (1, 1, 1) → 2 XOR 2 XOR 2 = 2
    The unique XOR values are {1, 2}, so the output is 2.
 */



class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n < 3){
            return n;
        }
        int bits = 0;
        int x = n;
        while (x > 0){
            bits++;
            x >>= 1;
        }
        return 1 << bits;
    }
};