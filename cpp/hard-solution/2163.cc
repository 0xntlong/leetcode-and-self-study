/**
2163. Minimum Difference in Sums After Removal of Elements
    You are allowed to remove any subsequence of elements of size exactly n from nums. The remaining 2 * n elements will be divided into two equal parts:

    The first n elements belonging to the first part and their sum is sumfirst.
    The next n elements belonging to the second part and their sum is sumsecond.
    The difference in sums of the two parts is denoted as sumfirst - sumsecond.

    For example, if sumfirst = 3 and sumsecond = 2, their difference is 1.
    Similarly, if sumfirst = 2 and sumsecond = 3, their difference is -1.
    Return the minimum difference possible between the sums of the two parts after the removal of n elements.

    Example :

    Input: nums = [3,1,2]
    Output: -1
    Explanation: Here, nums has 3 elements, so n = 1. 
    Thus we have to remove 1 element from nums and divide the array into two equal parts.
    - If we remove nums[0] = 3, the array will be [1,2]. The difference in sums of the two parts will be 1 - 2 = -1.
    - If we remove nums[1] = 1, the array will be [3,2]. The difference in sums of the two parts will be 3 - 2 = 1.
    - If we remove nums[2] = 2, the array will be [3,1]. The difference in sums of the two parts will be 3 - 1 = 2.
    The minimum difference between sums of the two parts is min(-1,1,2) = -1. 
 */


#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        priority_queue<int> maxHeap;
        long long leftSum = 0;
        vector<long long> leftDiff(n + 1);
        for (int i = 0; i < n; i++){
            maxHeap.push(nums[i]);
            leftSum += nums[i];
        }
        leftDiff[0] = leftSum;
        for (int i = n; i < 2 * n; ++i) {
            int num = nums[i];
            if (num < maxHeap.top()) {
                leftSum += num - maxHeap.top();
                maxHeap.pop();
                maxHeap.push(num);
            }
            leftDiff[i - n + 1] = leftSum;
        }
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long rightSum = 0;
        for (int i = 2 * n; i < 3 * n; i++){
            minHeap.push(nums[i]);
            rightSum += nums[i];
        }
        long long minDiff = leftDiff[n] - rightSum;
        for (int i = 2 * n - 1; i >= n; i--){
            if (!minHeap.empty() && nums[i] > minHeap.top()){
                rightSum += nums[i] - minHeap.top();
                minHeap.pop();
                minHeap.push(nums[i]);
            }
            int diffIndex = i - n;
            minDiff = min(minDiff, leftDiff[diffIndex] - rightSum);
        
        }
        return minDiff;
    }
};