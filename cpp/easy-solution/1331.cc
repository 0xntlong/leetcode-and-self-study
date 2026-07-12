/**
1331. Rank Transform of an Array
    Given an array of integers arr, replace each element with its rank.
    The rank represents how large the element is. The rank has the following rules:
    Rank is an integer starting from 1.
    The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
    Rank should be as small as possible.

    Example 
    Input: arr = [40,10,20,30]
    Output: [4,1,2,3]
    Explanation: 40 is the largest element. 10 is the smallest. 20 is the second smallest. 30 is the third smallest.
 */

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, int> rankMap;
        vector<int> sortedArray = arr;
        sort(sortedArray.begin(), sortedArray.end());
        int rank = 1;
        for (int x : sortedArray) {
            if (!rankMap.count(x)) {
                rankMap[x] = rank;
                rank++;
            }
        }
        vector<int> result;
        for (int x : arr) {
            result.push_back(rankMap[x]);
        }
        return result;
    }
};