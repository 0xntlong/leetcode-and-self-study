/*
2032. Two Out of Three
    Given three integer arrays nums1, nums2, and nums3, return a distinct array containing all the values that are present in at least two out of the three arrays. You may return the values in any order.
    
    Example:
    Input: nums1 = [1,1,3,2], nums2 = [2,3], nums3 = [3]
    Output: [3,2]
    Explanation: The values that are present in at least two arrays are:
    - 3, in all three arrays.
    - 2, in nums1 and nums2.
*/


#include <vector>
#include <map>
#include <set>
using namespace std;
class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> ans;
        map<int, int> hashmap;
        set<int>s1(nums1.begin(), nums1.end());
        set<int>s2(nums2.begin(), nums2.end());
        set<int>s3(nums3.begin(), nums3.end());
        for (int i : s1){
            hashmap[i]++;
        }
        for (int i : s2){
            hashmap[i]++;
        }
        for (int i : s3){
            hashmap[i]++;
        }
        for (auto freq : hashmap){
            if (freq.second >= 2){
                ans.push_back(freq.first);
            }
        }
        return ans;
    }
};