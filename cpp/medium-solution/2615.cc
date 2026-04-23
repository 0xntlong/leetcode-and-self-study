/**
2615. Sum of Distances
    You are given a 0-indexed integer array nums. There exists an array arr of length nums.length, where arr[i] is the sum of |i - j| over all j such that nums[j] == nums[i] and j != i. If there is no such j, set arr[i] to be 0.
    Return the array arr.
    Example :
    Input: nums = [1,3,1,1,2]
    Output: [5,0,3,4,0]
    Explanation: 
    When i = 0, nums[0] == nums[2] and nums[0] == nums[3]. Therefore, arr[0] = |0 - 2| + |0 - 3| = 5. 
    When i = 1, arr[1] = 0 because there is no other index with value 3.
    When i = 2, nums[2] == nums[0] and nums[2] == nums[3]. Therefore, arr[2] = |2 - 0| + |2 - 3| = 3. 
    When i = 3, nums[3] == nums[0] and nums[3] == nums[2]. Therefore, arr[3] = |3 - 0| + |3 - 2| = 4. 
    When i = 4, arr[4] = 0 because there is no other index with value 2. 
 */

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> d;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            d[nums[i]].push_back(i);
        }
        vector<long long> res(n, 0);
        for (auto& [_, v] : d) {
            if (v.size() > 1) {
                int c = v.size();
                int i = v[0];
                long long sum = 0;
                for (int x : v) 
                    sum += x;
                res[i] = sum - 1LL * c * i;
                int x = 0, y = c - 2;
                for (int k = 1; k < c; k++) {
                    int nidx = v[k];
                    res[nidx] = res[i] + 1LL * (x - y) * (nidx - i);
                    x++;
                    y--;
                    i = nidx;
                }
            }
        }
        return res;
    }
};