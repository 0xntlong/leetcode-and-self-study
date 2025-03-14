/*
2226. Maximum Number of Candies Allocated to K Children
    You are given a 0-indexed integer array candies. Each element in the array denotes a pile of candies of size candies[i]. You can divide each pile into any number of sub piles, but you cannot merge two piles together.
    You are also given an integer k. You should allocate piles of candies to k children such that each child gets the same number of candies. Each child can be allocated candies from only one pile of candies and some piles of candies may go unused.
    Return the maximum number of candies each child can get.
    Example :
    Input: candies = [5,8,6], k = 3
    Output: 5
    Explanation: We can divide candies[1] into 2 piles of size 5 and 3, and candies[2] into 2 piles of size 5 and 1. We now have five piles of candies of sizes 5, 5, 3, 5, and 1. We can allocate the 3 piles of size 5 to 3 children. It can be proven that each child cannot receive more than 5 candies.
*/

#include <vector>
#include <numeric>
using namespace std;
class Solution {
    private:
        bool Distribute(vector<int>& candies, int candy, int k){
            long long count = 0;
            for (int c : candies){
                count += c / candy;
                if (count >= k)
                    return true;
            }
            return false;
        }
    public:
        int maximumCandies(vector<int>& candies, long long k) {
            long long total = accumulate(candies.begin(), candies.end(), 0LL);
            if (total < k)
                return 0;
            int left = 1, right = total / k;
            while (left < right){
                int mid = (left + right + 1) / 2;
                if (Distribute(candies, mid, k)){
                    left = mid;
                } else {
                    right = mid -1;
                }
            }
            return left;
        }
    };