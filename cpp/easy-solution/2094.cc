/*
2094. Finding 3-Digits Even Numbers
    You are given an integer array digits, where each element is a digit. The array may contain duplicates.
    You need to find all the unique integers that follow the given requirements:
    The integer consists of the concatenation of three elements from digits in any arbitrary order.
    The integer does not have leading zeros.
    The integer is even.
    For example, if the given digits were [1, 2, 3], integers 132 and 312 follow the requirements.
    Return a sorted array of the unique integers.

    Example :
    Input: digits = [2,1,3,0]
    Output: [102,120,130,132,210,230,302,310,312,320]
    Explanation: All the possible integers that follow the requirements are in the output array. 
    Notice that there are no odd integers or integers with leading zeros.
*/

#include <vector>
using namespace std;

class Solution {
    vector<int> res;
    int freq[10] = {};
    void dfs(int n = 0){
        if (n > 99){
            if (!(n & 1))
                res.push_back(n);
            return;
        }
        for (int i = !n; i < 10; i++){
            if (freq[i]){
                freq[i]--;
                dfs(n * 10 + i);
                freq[i]++;
            }
        }
    }
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        for (int d : digits)
            freq[d]++;
        dfs();
        return res;
    }
};