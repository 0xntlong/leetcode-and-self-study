/*
1980. Find Unique Binary String
    Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.
    Example :
    Input: nums = ["01","10"]
    Output: "11"
    Explanation: "11" does not appear in nums. "00" would also be correct.
*/

#include <vector>
#include <string>
using namespace std;
class Solution {
    public:
        string findDifferentBinaryString(vector<string>& nums) {
            string res;
            for (int i = 0; i < nums.size(); i++){
                if (nums[i][i] == '0'){
                    res += '1';
                } else {
                    res += '0';
                }
            }
            return res;
        }
    };