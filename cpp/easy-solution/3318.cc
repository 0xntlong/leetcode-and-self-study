/**
3318. Find X-Sum of All K-Long Subarrays I
    You are given an array nums of n integers and two integers k and x.
    The x-sum of an array is calculated by the following procedure:
    Count the occurrences of all elements in the array.
    Keep only the occurrences of the top x most frequent elements. If two elements have the same number of occurrences, the element with the bigger value is considered more frequent.
    Calculate the sum of the resulting array.
    Note that if an array has less than x distinct elements, its x-sum is the sum of the array.
    Return an integer array answer of length n - k + 1 where answer[i] is the x-sum of the subarray nums[i..i + k - 1].

    Example :
    Input: nums = [1,1,2,2,3,4,2,3], k = 6, x = 2
    Output: [6,10,12]
    Explanation:
    For subarray [1, 1, 2, 2, 3, 4], only elements 1 and 2 will be kept in the resulting array. Hence, answer[0] = 1 + 1 + 2 + 2.
    For subarray [1, 2, 2, 3, 4, 2], only elements 2 and 4 will be kept in the resulting array. Hence, answer[1] = 2 + 2 + 2 + 4. Note that 4 is kept in the array since it is bigger than 3 and 1 which occur the same number of times.
    For subarray [2, 2, 3, 4, 2, 3], only elements 2 and 3 are kept in the resulting array. Hence, answer[2] = 2 + 2 + 2 + 3 + 3.
 */


#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i <= n - k; i++){
            unordered_map<int, int> freq;
            for (int j = i; j < i + k; j++){
                freq[nums[j]]++;
            }
            vector<pair<int, int>> items(freq.begin(), freq.end());
            sort(items.begin(), items.end(), [](auto &a, auto &b){
                if (a.second == b.second)
                    return a.first > b.first;
                return a.second > b.second;
            });
            int total = 0;
            for (int j = 0; j < x && j < (int)items.size(); j++){
                total += items[j].first * items[j].second;
            }
            res.push_back(total);
        }
        return res;
    }
};