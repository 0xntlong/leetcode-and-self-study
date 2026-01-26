/**
1200. Minimum Absolute Difference
    Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.
    Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows
    a, b are from arr
    a < b
    b - a equals to the minimum absolute difference of any two elements in arr
    Example :
    Input: arr = [4,2,1,3]
    Output: [[1,2],[2,3],[3,4]]
    Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.
 */


#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int min_diff = INT_MAX;
        for (int i = 0; i < n - 1; i++){
            min_diff = min(min_diff, arr[i + 1] - arr[i]);
        }
        vector<vector<int>> res;
        for (int i = 0; i < n - 1; i++){
            if (arr[i + 1] - arr[i] == min_diff){
                res.push_back({arr[i], arr[i + 1]});
            }
        }
        return res;
    }
};