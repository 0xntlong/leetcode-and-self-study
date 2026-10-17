/**
3551. Minimum Swaps to Sort by Digit Sum
    You are given an array nums of distinct positive integers. You need to sort the array in increasing order based on the sum of the digits of each number. If two numbers have the same digit sum, the smaller number appears first in the sorted order.
    Return the minimum number of swaps required to rearrange nums into this sorted order.
    A swap is defined as exchanging the values at two distinct positions in the array.
    Example :
    Input: nums = [37,100]
    Output: 1
    Explanation:
    Compute the digit sum for each integer: [3 + 7 = 10, 1 + 0 + 0 = 1] → [10, 1]
    Sort the integers based on digit sum: [100, 37]. Swap 37 with 100 to obtain the sorted order.
    Thus, the minimum number of swaps required to rearrange nums is 1.
 */



class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<tuple<int, int, int>> arr;

        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            int digitSum = 0;

            while (curr > 0) {
                digitSum += curr % 10;
                curr /= 10;
            }

            arr.push_back({digitSum, nums[i], i});
        }

        sort(arr.begin(), arr.end());

        vector<int> perm(n);

        for (int i = 0; i < n; i++) {
            perm[i] = get<2>(arr[i]);
        }

        vector<bool> visited(n, false);
        int cycles = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                continue;
            }

            cycles++;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = perm[j];
            }
        }

        return n - cycles;
    }
};