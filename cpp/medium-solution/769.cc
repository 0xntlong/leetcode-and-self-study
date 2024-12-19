/*
769. max Chunks To Make Sorted
    You are given an integer array arr of length n that represents a permutation of the integers in the range [0, n - 1].
    We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.
    Return the largest number of chunks we can make to sort the array.

    Example :
    Input: arr = [4,3,2,1,0]
    Output: 1
    Explanation:
    Splitting into two or more chunks will not return the required result.
    For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn't sorted.
*/


#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if (arr.empty())
            return 0;
        int count = 0, max_val = 0;
        for (int i = 0; i < arr.size(); i++){
            max_val = max(max_val, arr[i]);
            if (max_val == i){
                count++;
            }
        }
        return count;
    }
};