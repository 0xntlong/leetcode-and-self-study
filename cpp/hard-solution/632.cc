/*
    632. Smallest Range Covering Elements from K Lists
    You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.
    We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.
    
    Example:
    Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
    Output: [20,24]
    Explanation: 
    List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
    List 2: [0, 9, 12, 20], 20 is in range [20,24].
    List 3: [5, 18, 22, 30], 22 is
*/

#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> elements;
        for (int k = 0; k < nums.size(); ++k) {
            for (int n : nums[k]) {
                elements.emplace_back(n, k);
            }
        }
        sort(elements.begin(), elements.end());
        
        int i = 0, k = 0;
        vector<int> ans;
        unordered_map<int, int> count;
        for (int j = 0; j < elements.size(); ++j) {
            if (count[elements[j].second] == 0) {
                ++k;
            }
            ++count[elements[j].second];

            if (k == nums.size()) {
                while (count[elements[i].second] > 1) {
                    --count[elements[i].second];
                    ++i;
                }
                if (ans.empty() || ans[1] - ans[0] > elements[j].first - elements[i].first) {
                    ans = {elements[i].first, elements[j].first};
                }
            }
        }
        return ans;
    }
};