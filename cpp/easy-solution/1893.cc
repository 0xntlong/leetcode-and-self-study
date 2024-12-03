/*
1893. Check if All the Integers in a Range Are Covered
    You are given a 2D integer array ranges and two integers left and right. Each ranges[i] = [starti, endi] represents an inclusive interval between starti and endi.
    Return true if each integer in the inclusive range [left, right] is covered by at least one interval in ranges. Return false otherwise.
    An integer x is covered by an interval ranges[i] = [starti, endi] if starti <= x <= endi.

    Example :
    Input: ranges = [[1,2],[3,4],[5,6]], left = 2, right = 5
    Output: true
    Explanation: Every integer between 2 and 5 is covered:
    - 2 is covered by the first range.
    - 3 and 4 are covered by the second range
*/

#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        unordered_map<int, int> mp;
        for (auto x: ranges){
            for (int i = x[0]; i <= x[1]; i++)
                mp[i]++;
        }
        for (int i = left; i <= right; i++){
            if (mp.find(i) == mp.end())
                return false;
        }
        return true;
    }
};