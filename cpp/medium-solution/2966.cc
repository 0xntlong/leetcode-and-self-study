/**
2966. Divide Array Into Arrays With Max Difference
    You are given an integer array nums of size n where n is a multiple of 3 and a positive integer k.
    Divide the array nums into n / 3 arrays of size 3 satisfying the following condition:
    The difference between any two elements in one array is less than or equal to k.
    Return a 2D array containing the arrays. If it is impossible to satisfy the conditions, return an empty array. And if there are multiple answers, return any of them.

    Example :
    Input: nums = [1,3,4,8,7,9,3,5,1], k = 2
    Output: [[1,1,3],[3,4,5],[7,8,9]]
    Explanation:
    The difference between any two elements in each array is less than or equal to 2.
 */

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        const int n = nums.size(), maxVal = *max_element(nums.begin(), nums.end());
        vector<int> freq(maxVal + 1, 0);
        for (const int& num : nums){
            freq[num]--;
        }
        vector<vector<int>> res(n / 3, vector<int>(3, 0));
        int x = 0;
        for (int i = 0; i < n / 3; i++){
            for (int j = 0; j < 3; j++){
                while (x <= maxVal && freq[x] == 0){
                    x++;
                }
                res[i][j] = x;
                freq[x]++;
            }
            if (res[i][2] - res[i][0] > k){
                return {};
            }
        }
        return res;
    }
};