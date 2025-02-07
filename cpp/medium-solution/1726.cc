/*
1726. Tuple with Same Product
Given an array nums of distinct positive integers, return the number of tuples (a, b, c, d) such that a * b = c * d where a, b, c, and d are elements of nums, and a != b != c != d.
    Example 1:
    Input: nums = [2,3,4,6]
    Output: 8
    Explanation: There are 8 valid tuples:
    (2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
    (3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)
    Example 2:
    Input: nums = [1,2,4,5,10]
    Output: 16
    Explanation: There are 16 valid tuples:
    (1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
    (2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
    (2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,5,4)
    (4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)

*/

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        int tupleSameProduct(vector<int>& nums) {
            const int n = nums.size(), N = n * (n - 1) / 2;
            vector<int> product;
            product.reserve(N);
            for (int i = 0; i < n - 1; i++){
                for (int j = i + 1; j < n; j ++){
                    product.push_back(nums[i] * nums[j]);
                }
            }
            sort(product.begin(), product.end());
            int res = 0, j = 1, f = 1;
            for (int i = 2; i < N; i++){
                if (product[j] == product[i])
                    f++;
                else {
                    if (f > 1)
                        res += f*(f - 1) * 4;
                        f = 1;
                        j = i;
                }
            }
            return res;
        }
    };