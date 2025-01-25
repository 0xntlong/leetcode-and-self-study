/*
2948. Make Lexicographically Smallest Array by Swapping Elements
    You are given a 0-indexed array of positive integers nums and a positive integer limit.
    In one operation, you can choose any two indices i and j and swap nums[i] and nums[j] if |nums[i] - nums[j]| <= limit.
    Return the lexicographically smallest array that can be obtained by performing the operation any number of times.
    An array a is lexicographically smaller than an array b if in the first position where a and b differ, array a has an element that is less than the corresponding element in b. For example, the array [2,10,3] is lexicographically smaller than the array [10,2,3] because they differ at index 0 and 2 < 10.

    Example :
    Input: nums = [1,5,3,9,8], limit = 2
    Output: [1,3,5,8,9]
    Explanation: Apply the operation 2 times:
    - Swap nums[1] with nums[2]. The array becomes [1,3,5,9,8]
    - Swap nums[3] with nums[4]. The array becomes [1,3,5,8,9]
    We cannot obtain a lexicographically smaller array by applying any more operations.
    Note that it may be possible to get the same result by doing different operations.

*/

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int, int >> Pair;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            Pair.push_back({nums[i], i});
        }
        sort(Pair.begin(), Pair.end());
        vector<int> x[n];
        vector<int> y[n];
        int j = 0, cur = Pair[0].first;

        x[j].push_back(Pair[0].first);
        y[j].push_back(Pair[0].second);
        for (int i = 1; i < n; i++){
            if (Pair[i].first - cur > limit){
                j++;
            }
            x[j].push_back(Pair[i].first);
            y[j].push_back(Pair[i].second);
            cur = Pair[i].first;
        }
        for (int i = 0; i < n; i++){
            sort(y[i].begin(), y[i].end());
        }
        vector<int> res(n);

        for (int i = 0; i < n; i++){
            for (int j = 0; j < x[i].size(); j++){
                res[y[i][j]] = x[i][j];
            }
        }
        return res;
    }
};