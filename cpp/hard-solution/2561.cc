/**
2561. Rearranging Fruits 
    You have two fruit baskets containing n fruits each. You are given two 0-indexed integer arrays basket1 and basket2 representing the cost of fruit in each basket. You want to make both baskets equal. To do so, you can use the following operation as many times as you want:

    Chose two indices i and j, and swap the ith fruit of basket1 with the jth fruit of basket2.
    The cost of the swap is min(basket1[i],basket2[j]).
    Two baskets are considered equal if sorting them according to the fruit cost makes them exactly the same baskets.

    Return the minimum cost to make both the baskets equal or -1 if impossible.

    Example :

    Input: basket1 = [4,2,2,2], basket2 = [1,4,1,2]
    Output: 1
    Explanation: Swap index 1 of basket1 with index 0 of basket2, which has cost 1. Now basket1 = [4,1,2,2] and basket2 = [2,4,1,2]. Rearranging both the arrays makes them equal.

 */


#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> count1, count2;
        int minX = INT_MAX;
        for (int x : basket1){
            count1[x]++;
            minX = min(minX, x);
        }
        for (int x : basket2){
            count2[x]++;
            minX = min(minX, x);
        }
        for (auto& [key, cnt1] : count1){
            int min_count = min(cnt1, count2[key]);
            count1[key] -= min_count;
            count2[key] -= min_count;
        }
        for (auto& [key, val] : count1){
            if (val % 2 != 0)
                return -1;
        }
        for (auto& [key, val] : count2){
            if (val % 2 != 0)
                return -1;
        }
        vector<int> swap1, swap2;
        for (auto& [key, val] : count1){
            for (int i = 0; i < val / 2; i++){
                swap1.push_back(key);
            }
        }
        for (auto& [key, val] : count2){
            for (int i = 0; i < val / 2; i++){
                swap2.push_back(key);
            }
        }
        sort(swap1.begin(), swap1.end());
        sort(swap2.rbegin(), swap2.rend());
        long long res = 0;
        for (int i = 0; i < swap1.size(); i++){
            res += min({swap1[i], swap2[i], 2 * minX});
        }
        return res;
    }
};