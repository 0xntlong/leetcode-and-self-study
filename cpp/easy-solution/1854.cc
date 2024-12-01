/*
1854. Maximum Population Year
    You are given a 2D integer array logs where each logs[i] = [birthi, deathi] indicates the birth and death years of the ith person.
    The population of some year x is the number of people alive during that year. The ith person is counted in year x's population if x is in the inclusive range [birthi, deathi - 1]. Note that the person is not counted in the year that they die.
    Return the earliest year with the maximum population.

    Example :
    Input: logs = [[1993,1999],[2000,2010]]
    Output: 1993
    Explanation: The maximum population is 1, and 1993 is the earliest year with this population.
*/

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<pair<int, int>> vals;
        for (auto& log : logs){
            vals.emplace_back(log[0], 1);
            vals.emplace_back(log[1], -1);
        }
        sort(vals.begin(), vals.end());
        int ans = 0, prefix = 0, most = 0;
        for (auto& val : vals){
            prefix += val.second;
            if (prefix > most){
                most = prefix;
                ans = val.first;
            }
        }
        return ans;
    }
};