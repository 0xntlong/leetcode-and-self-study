/**
955. Delete Columns to Make Sorted II
    You are given an array of n strings strs, all of the same length.
    We may choose any deletion indices, and we delete all the characters in those indices for each string.
    For example, if we have strs = ["abcdef","uvwxyz"] and deletion indices {0, 2, 3}, then the final array after deletions is ["bef", "vyz"].
    Suppose we chose a set of deletion indices answer such that after deletions, the final array has its elements in lexicographic order (i.e., strs[0] <= strs[1] <= strs[2] <= ... <= strs[n - 1]). Return the minimum possible value of answer.length.

    Example :
    Input: strs = ["ca","bb","ac"]
    Output: 1
    Explanation: 
    After deleting the first column, strs = ["a", "b", "c"].
    Now strs is in lexicographic order (ie. strs[0] <= strs[1] <= strs[2]).
    We require at least 1 deletion since initially strs was not in lexicographic order, so the answer is 1.
 */




class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int col = strs[0].size();  
        int row = strs.size();     
        int res = 0;  
        vector<bool> sorted_pairs(row - 1, false);  
        for (int c = 0; c < col; ++c) {
            bool check = true;  
            for (int r = 0; r < row - 1; ++r) {
                if (!sorted_pairs[r] && strs[r][c] > strs[r + 1][c]) {
                    check = false;  
                    break;
                }
            }
            if (check == false) {
                res++;  
                continue; 
            }
            for (int r = 0; r < row - 1; ++r) {
                if (!sorted_pairs[r] && strs[r][c] < strs[r + 1][c]) {
                    sorted_pairs[r] = true;  
                }
            }
        }
        return res;
    }
};