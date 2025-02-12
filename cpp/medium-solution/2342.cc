/*
2342. Max Sum of a Pair With Equal Sum of Digits
    You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].
    Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.

    Example :
    Input: nums = [18,43,36,13,7]
    Output: 54
    Explanation: The pairs (i, j) that satisfy the conditions are:
    - (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
    - (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
    So the maximum sum that we can obtain is 54.
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        int maximumSum(vector<int>& nums) {
            auto sum_digit = [](int num){
                int total = 0;
                while (num){
                    total += num % 10;
                    num /= 10;
                }
                return total;
            };
            unordered_map<int, pair<int, int>> pairs;
            int max_sum = -1;
            for (int n : nums){
                int key = sum_digit(n);
                auto& [curr, next] = pairs[key];
                if (n > curr){
                    next = curr;
                    curr = n;
                } else if (n > next){
                    next = n;
                }
                if (next > 0){
                    max_sum = max(max_sum, curr + next);
                }
            }
            return max_sum;
        }
    };