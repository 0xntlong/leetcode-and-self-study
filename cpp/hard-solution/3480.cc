/**
3480. Maximize Subarrays After Removing One Conflicting Pair
    You are given an integer n which represents an array nums containing the numbers from 1 to n in order. Additionally, you are given a 2D array conflictingPairs, where conflictingPairs[i] = [a, b] indicates that a and b form a conflicting pair.
    Remove exactly one element from conflictingPairs. Afterward, count the number of non-empty subarrays of nums which do not contain both a and b for any remaining conflicting pair [a, b].
    Return the maximum number of subarrays possible after removing exactly one conflicting pair.
    Example :
    Input: n = 4, conflictingPairs = [[2,3],[1,4]]
    Output: 9
    Explanation:
    Remove [2, 3] from conflictingPairs. Now, conflictingPairs = [[1, 4]].
    There are 9 subarrays in nums where [1, 4] do not appear together. They are [1], [2], [3], [4], [1, 2], [2, 3], [3, 4], [1, 2, 3] and [2, 3, 4].
    The maximum number of subarrays we can achieve after removing one element from conflictingPairs is 9.
 */


#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<vector<int>> conflict(n + 1);
        for (const auto&pair : conflictingPairs){
            int u = pair[0], v = pair[1];
            conflict[max(u, v)].push_back(min(u, v));
        }
        long long res = 0;
        int max_diff = 0, max_left = 0;
        vector<long long> prefix(n + 1, 0);
        for (int r = 1; r <= n; r++){
            for (int l :conflict[r]){
                if (l > max_diff){
                    int temp = max_diff;
                    max_diff = l;
                    max_left = temp;
                } else if ( l > max_left){
                    max_left = l;
                }
            }
            res += r - max_diff;
            if (max_diff > 0){
                prefix[max_diff] += max_diff - max_left;
            }
        }
        return res + *max_element(prefix.begin(), prefix.end());
    }
};