/**
2411. Smallest Subarrays With Maximum Bitwise OR
    In other words, let Bij be the bitwise OR of the subarray nums[i...j]. You need to find the smallest subarray starting at i, such that bitwise OR of this subarray is equal to max(Bik) where i <= k <= n - 1.
    The bitwise OR of an array is the bitwise OR of all the numbers in it.

    Return an integer array answer of size n where answer[i] is the length of the minimum sized subarray starting at i with maximum bitwise OR.

    A subarray is a contiguous non-empty sequence of elements within an array.

    Example :

    Input: nums = [1,0,2,1,3]
    Output: [3,3,2,2,1]
    Explanation:
    The maximum possible bitwise OR starting at any index is 3. 
    - Starting at index 0, the shortest subarray that yields it is [1,0,2].
    - Starting at index 1, the shortest subarray that yields the maximum bitwise OR is [0,2,1].
    - Starting at index 2, the shortest subarray that yields the maximum bitwise OR is [2,1].
    - Starting at index 3, the shortest subarray that yields the maximum bitwise OR is [1,3].
    - Starting at index 4, the shortest subarray that yields the maximum bitwise OR is [3].
    Therefore, we return [3,3,2,2,1]. 

 */


#include <vector>
using namespace std;
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++){
            res[i] = 1;
            for (int j = i - 1; j >= 0 && (nums[j] != (nums[i] | nums[j])); j--){
                nums[j] = nums[i] | nums[j];
                res[j] = i - j + 1;
            }
        }
        return res;
    }
};