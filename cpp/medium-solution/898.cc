/**
898. Bitwise ORs of Subarrays
    Given an integer array arr, return the number of distinct bitwise ORs of all the non-empty subarrays of arr.
    The bitwise OR of a subarray is the bitwise OR of each integer in the subarray. The bitwise OR of a subarray of one integer is that integer.
    A subarray is a contiguous non-empty sequence of elements within an array.

    Example :
    Input: arr = [0]
    Output: 1
    Explanation: There is only one possible result: 0.
 */


#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res;
        const int n = arr.size();
        for (int i = 0; i < n; i++){
            const int x = arr[i];
            int next = 0, curr = x;
            res.insert(curr);
            for (int j = i - 1; j >= 0; j--){
                next |= arr[j];
                curr = next | x;
                if (next == curr)
                    break;
                res.insert(curr);
            }
        }
        return res.size();
    }
};