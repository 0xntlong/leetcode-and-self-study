/*
2614. Prime In Diagonal
    You are given a 0-indexed two-dimensional integer array nums.
    Return the largest prime number that lies on at least one of the diagonals of nums. In case, no prime is present on any of the diagonals, return 0.
    Note that:
    An integer is prime if it is greater than 1 and has no positive integer divisors other than 1 and itself.
    An integer val is on one of the diagonals of nums if there exists an integer i for which nums[i][i] = val or an i for which nums[i][nums.length - i - 1] = val.
    In the above diagram, one diagonal is [1,5,9] and another diagonal is [3,5,7].
    Example :
    Input: nums = [[1,2,3],[5,6,7],[9,10,11]]
    Output: 11
    Explanation: The numbers 1, 3, 6, 9, and 11 are the only numbers present on at least one of the diagonals. Since 11 is the largest prime, we return 11.
*/

#include <vector>
#include <cmath>
using namespace std;
class Solution {
    public:
        bool isPrime(int n){
            if (n <= 1)
                return false;
            if (n == 2)
                return true;
            if (n % 2 == 0)
                return false;
            for (int i = 3; i <= sqrt(n); i += 2){
                if (n % i == 0){
                    return false;
                }
            }
            return true;
        }
        int diagonalPrime(vector<vector<int>>& nums) {
            int n = nums.size(); 
            int maxPrime = 0;
            for (int i = 0; i < n; i++){
                if (isPrime(nums[i][i])){
                    maxPrime = max(maxPrime, nums[i][i]);
                }
                if (isPrime(nums[i][n - i - 1])){
                    maxPrime = max(maxPrime, nums[i][n - i - 1]);
                }
            }
            return maxPrime;
        }
    };