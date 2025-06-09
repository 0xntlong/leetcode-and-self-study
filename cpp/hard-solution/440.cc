/**
440. K-th Smallest in Lexicographical Order
    Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].

    Example 1:
    Input: n = 13, k = 2
    Output: 10
    Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
*/


#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int count(long n, long a, long b){
        int i = 0;
        while (a <= n){
            i += min(n + 1L, b) - a;
            a *= 10;
            b *= 10;
        }
        return i;
    }
    int findKthNumber(int n, int k) {
        int res = 1;
        k--;
        while (k){
            int i = count(n, res, res + 1);
            if (i <= k){
                k -= i;
                res++;
            } else {
                res *= 10;
                k--;
            }
        }
        return res;
    }
};