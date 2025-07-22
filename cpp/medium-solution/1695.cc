/**
1695. Maximum Erasure Value
    You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.
    Return the maximum score you can get by erasing exactly one subarray.
    An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).

    Example :
    Input: nums = [4,2,4,5,6]
    Output: 17
    Explanation: The optimal subarray here is [2,4,5,6].
 */


#include <vector>
#include <bitset>
using namespace std;
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        bitset<10001> seen;
        int l = 0, allSum = 0, res = 0;
        for (int r = 0; r < nums.size(); r++){
            while (seen[nums[r]]){
                seen[nums[l]] = 0;
                allSum -= nums[l];
                l++;
            }
            seen[nums[r]] = 1;
            allSum += nums[r];
            res = max(res, allSum);
        }
        return res;
    }
};