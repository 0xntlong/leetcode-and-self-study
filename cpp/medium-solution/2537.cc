/*
2537. Count the Number of Good Subarrays
    Given an integer array nums and an integer k, return the number of good subarrays of nums.
    A subarray arr is good if there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].
    A subarray is a contiguous non-empty sequence of elements within an array.
    Example :
    Input: nums = [1,1,1,1,1], k = 10
    Output: 1
    Explanation: The only good subarray is the array nums itself.
*/


class Solution {
    public:
        long long countGood(vector<int>& nums, int k) {
            int n = nums.size();
            unordered_map<int, int> freq;
            long long cnt = 0;
            long long pairs = 0;
            int i = 0;
            for (int j = 0; j < n; j++){
                pairs += freq[nums[j]];
                freq[nums[j]]++;
                while (pairs >= k){
                    cnt += (n - j);
                    freq[nums[i]]--;
                    pairs -= freq[nums[i]];
                    i++;
                }
            }
            return cnt++;
        }
    };