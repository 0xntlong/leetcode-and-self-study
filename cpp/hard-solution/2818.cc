/*
2818. Apply Operations to Maximize Score
    You are given an array nums of n positive integers and an integer k.
    Initially, you start with a score of 1. You have to maximize your score by applying the following operation at most k times:
    Choose any non-empty subarray nums[l, ..., r] that you haven't chosen previously.
    Choose an element x of nums[l, ..., r] with the highest prime score. If multiple such elements exist, choose the one with the smallest index.
    Multiply your score by x.
    Here, nums[l, ..., r] denotes the subarray of nums starting at index l and ending at the index r, both ends being inclusive.
    The prime score of an integer x is equal to the number of distinct prime factors of x. For example, the prime score of 300 is 3 since 300 = 2 * 2 * 3 * 5 * 5.
    Return the maximum possible score after applying at most k operations.
    Since the answer may be large, return it modulo 109 + 7.
    Example :
    Input: nums = [8,3,9,3,8], k = 2
    Output: 81
    Explanation: To get a score of 81, we can apply the following operations:
    - Choose subarray nums[2, ..., 2]. nums[2] is the only element in this subarray. Hence, we multiply the score by nums[2]. The score becomes 1 * 9 = 9.
    - Choose subarray nums[2, ..., 3]. Both nums[2] and nums[3] have a prime score of 1, but nums[2] has the smaller index. Hence, we multiply the score by nums[2]. The score becomes 9 * 9 = 81.
    It can be proven that 81 is the highest score one can obtain.
*/

#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


long long isPrimeScore(int num){
    long long score = 0;
    if (num % 2 == 0){
        score += 1;
        while (num % 2 == 0){
            num /= 2;
        }
    }
    for (int p = 3; p < sqrt(num); p += 2){
        if (num % p == 0){
            score += 1;
            while (num % p == 0){
                num /= p;
            }
        }
    }
    if (num > 1){
        score += 1;
    }
    return score;
}
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        vector<long long> scores;
        for (int num : nums){
            scores.push_back(isPrimeScore(num));
        }
        scores.push_back(MOD);
        int n = nums.size();
        vector<int>lefts(n, 0), rights(n, 0);
        vector<int> stack1;
        for (int i = 0; i < n; i++){
            while (!stack1.empty() && scores[i] > scores[stack1.back()]){  
                stack1.pop_back();
            }
            lefts[i] = stack1.empty() ? -1 : stack1.back();  
            stack1.push_back(i);
        }
        vector<int> stack2;
        stack2.push_back(n);
        for (int i = n - 1; i >= 0; i--){
            while (!stack2.empty() && scores[i] >= scores[stack2.back()]){ 
                stack2.pop_back();
            }
            rights[i] = stack2.empty() ? n : stack2.back();  
            stack2.push_back(i);
        }
        long long max_score = 1;
        vector<pair<int, int>> sorted_nums;
        for (int i = 0; i < n; i++){
            sorted_nums.push_back({nums[i], i});
        }
        sort(sorted_nums.rbegin(), sorted_nums.rend());
        for (auto& [num, i] : sorted_nums){
            long long count = (long long)(i - lefts[i]) * (rights[i] - i);
            max_score = (max_score * modPow(num, min((long long)k, count), MOD)) % MOD;
            if (count >= k){
                break;
            }
            k -= count;
        }
        return max_score;
    }
    long long modPow(long long base, long long exp, long long mod){
        long long res = 1;
        base = base % mod;
        while (exp > 0){
            if (exp % 2 == 1){
                res = (res * base) % mod;
            }
            exp = exp / 2;
            base = (base * base) % mod;
        }
        return res;
    }
};