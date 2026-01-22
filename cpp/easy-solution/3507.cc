/**
3507. Minimum Pair Removal to Sort Array I
    Given an array nums, you can perform the following operation any number of times:
    Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
    Replace the pair with their sum.
    Return the minimum number of operations needed to make the array non-decreasing.
    An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).

    Example :
    Input: nums = [5,2,3,1]
    Output: 2
    Explanation:
    The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
    The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
    The array nums became non-decreasing in two operations.
 */


#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int opt = 0;
        auto is_sorted = [&](const vector<int>& arr) -> bool {
            for (int i = 1; i < (int)arr.size(); i++){
                if (arr[i] < arr[i - 1])
                    return false;
            }
            return true;
        };
        while (!is_sorted(nums)){
            int n = (int)nums.size();
            long long min_sum = LLONG_MAX;
            int idx = 0;
            for (int i = 0; i < n - 1; i++){
                long long pair_sum = (long long)nums[i] + nums[i + 1];
                if (pair_sum < min_sum){
                    min_sum = pair_sum;
                    idx = i;
                }
            }
            nums[idx] = (int)min_sum;
            nums.erase(nums.begin() + idx + 1);
            opt++;
        }
        return opt;
    }
};