/**
1390. Four Divisors
    Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors. If there is no such integer in the array, return 0.
    Example :
    Input: nums = [21,4,7]
    Output: 32
    Explanation: 
    21 has 4 divisors: 1, 3, 7, 21
    4 has 3 divisors: 1, 2, 4
    7 has 2 divisors: 1, 7
    The answer is the sum of divisors of 21 only.
 */


#include <vector>
using namespace std;

class Solution {
public:
    int div(int n){
        int sum = 0, cnt = 0;
        for (int i = 1; i * i <= n; i++){
            if (n % i)
                continue;
            cnt++;
            sum += i;
            if (i != n / i){
                cnt++;
                sum += n / i;
            }
            if (cnt > 4)
                break;
        }
        return cnt != 4 ? 0 : sum;
    }
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        for (const auto& n : nums){
            int sum = div(n);
            res += sum;
        }
        return res;
    }
};