/**
1590. Make Sum Divisible by P
    Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that the sum of the remaining elements is divisible by p. It is not allowed to remove the whole array.
    Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.
    A subarray is defined as a contiguous block of elements in the array.

    Example :
    Input: nums = [3,1,4,2], p = 6
    Output: 1
    Explanation: The sum of the elements in nums is 10, which is not divisible by 6. We can remove the subarray [4], and the sum of the remaining elements is 6, which is divisible by 6.
 */


#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        typedef long long ll;
        int n = nums.size();
        ll total = 0;
        for (int x : nums)
            total += x;
        int target = total % p;
        if (target == 0)
            return 0;
        unordered_map<int, int> dic;
        dic[0] = -1;
        ll curr = 0;
        int res = n;
        for (int i = 0; i < n; i++){
            curr = (curr + nums[i]) % p;
            int need = (curr - target + p) % p;
            if (dic.count(need)){
                res = min(res, i - dic[need]);
            }
            dic[curr] = i;
        }
        return res == n ? -1 : res;
    }
};