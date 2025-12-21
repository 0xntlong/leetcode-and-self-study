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



function minDeletionSize(strs: string[]): number {
    let col = strs[0].length; 
    let row = strs.length;     
    let res = 0; 
    let sortedPairs: boolean[] = Array(row - 1).fill(false); 
    for (let c = 0; c < col; ++c) {
        let check = true; 
        for (let r = 0; r < row - 1; ++r) {
            if (!sortedPairs[r] && strs[r][c] > strs[r + 1][c]) {
                check = false;
                break;
            }
        }
        if (!check) {
            res++;
            continue;
        }
        for (let r = 0; r < row - 1; ++r) {
            if (!sortedPairs[r] && strs[r][c] < strs[r + 1][c]) {
                sortedPairs[r] = true;  
            }
        }
    }

    return res;
};