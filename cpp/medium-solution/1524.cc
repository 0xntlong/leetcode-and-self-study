/*
1524. Number of Sub-arrays With Odd Sum
    Given an array of integers arr, return the number of subarrays with an odd sum.
    Since the answer can be very large, return it modulo 109 + 7.

    Example :
    Input: arr = [1,3,5]
    Output: 4
    Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
    All sub-arrays sum are [1,4,9,3,8,5].
    Odd sums are [1,9,3,5] so the answer is 4.
*/

#include <vector>
using namespace std;

class Solution {
    public:
        int numOfSubarrays(vector<int>& arr) {
            const int MOD = 1e9 + 7;
            long long odd = 0, even = 1, prefix = 0, res = 0;
            for (int i : arr){
                prefix += i;
                if (prefix % 2 == 0){
                    res = (res + odd) % MOD;
                    even++;
                } else {
                    res = (res + even) % MOD;
                    odd++;
                }
            }
            return res;
        }
    };