/**
3583. Count Special Triplets
    You are given an integer array nums.
    A special triplet is defined as a triplet of indices (i, j, k) such that:
    0 <= i < j < k < n, where n = nums.length
    nums[i] == nums[j] * 2
    nums[k] == nums[j] * 2
    Return the total number of special triplets in the array.
    Since the answer may be large, return it modulo 109 + 7.

    Example :
    Input: nums = [6,3,6]
    Output: 1
    Explanation:
    The only special triplet is (i, j, k) = (0, 1, 2), where:
    nums[0] = 6, nums[1] = 3, nums[2] = 6
    nums[0] = nums[1] * 2 = 3 * 2 = 6
    nums[2] = nums[1] * 2 = 3 * 2 = 6
 */



#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<long long, long long> dict1, dict2;
        long long res = 0;
        const int mod = 1e9 + 7;
        for (int num : nums){
            if (num % 2 == 0 && dict2.find(num / 2) != dict2.end()){
                res += dict2[num / 2];
                res %= mod;
            }
            if (dict1.find(num * 2) != dict1.end()){
                if (dict2.find(num) != dict2.end()){
                    dict2[num] += dict1[num * 2];
                } else {
                    dict2[num] = dict1[num * 2];
                }
            }
            dict1[num]++;
        }
        return res;
    }
};