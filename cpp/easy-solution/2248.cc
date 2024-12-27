/*
2248. Intersection of Two Arrays
    Given a 2D integer array nums where nums[i] is a non-empty array of distinct positive integers, return the list of integers that are present in each array of nums sorted in ascending order.

    Example :
    Input: nums = [[3,1,2,4,5],[1,2,3,4],[3,4,5,6]]
    Output: [3,4]
    Explanation: 
    The only integers present in each of nums[0] = [3,1,2,4,5], nums[1] = [1,2,3,4], and nums[2] = [3,4,5,6] are 3 and 4, so we return [3,4].
*/

#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n = nums.size();
        map<int, int> count;
        vector<int> matrix;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < nums[i].size(); j++){
                count[nums[i][j]]++;
            }
        }
        for (auto idx : count)
            if (idx.second == n)
                matrix.push_back(idx.first);
        return matrix;
    }
};