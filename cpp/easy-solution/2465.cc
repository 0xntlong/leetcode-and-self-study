/*
2465. Number of Distinct Averages
    You are given a 0-indexed integer array nums of even length.
    As long as nums is not empty, you must repetitively:
    Find the minimum number in nums and remove it.
    Find the maximum number in nums and remove it.
    Calculate the average of the two removed numbers.
    The average of two numbers a and b is (a + b) / 2.
    For example, the average of 2 and 3 is (2 + 3) / 2 = 2.5.
    Return the number of distinct averages calculated using the above process.
    Note that when there is a tie for a minimum or maximum number, any can be removed.

    Example :
    Input: nums = [4,1,4,0,3,5]
    Output: 2
    Explanation:
    1. Remove 0 and 5, and the average is (0 + 5) / 2 = 2.5. Now, nums = [4,1,4,3].
    2. Remove 1 and 4. The average is (1 + 4) / 2 = 2.5, and nums = [4,3].
    3. Remove 3 and 4, and the average is (3 + 4) / 2 = 3.5.
    Since there are 2 distinct numbers among 2.5, 2.5, and 3.5, we return 2.
*/


#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<double> res;
        while (!nums.empty()){
            int Max = nums.back();
            nums.pop_back();
            int Min = nums.front();
            nums.erase(nums.begin());
            double avg = (Max + Min) / 2.0;
            res.insert(avg);
        }
        return res.size();
    }
};