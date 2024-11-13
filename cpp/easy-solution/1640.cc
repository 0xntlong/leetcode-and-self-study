/*
1640. Check Array Formation Through Concatenation
    You are given an array of distinct integers arr and an array of integer arrays pieces, where the integers in pieces are distinct. Your goal is to form arr by concatenating the arrays in pieces in any order. However, you are not allowed to reorder the integers in each array pieces[i].
    Return true if it is possible to form the array arr from pieces. Otherwise, return false.

    Example :
    Input: arr = [15,88], pieces = [[88],[15]]
    Output: true
    Explanation: Concatenate [15] then [88]
*/

#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        std::unordered_map<int, int> hashmap;
        for (int i = 0; i < arr.size(); i++)
            hashmap[arr[i]] = i;
        for (const auto & p : pieces){
            if (p.size() == 1){
                if ( hashmap.find(p[0]) == hashmap.end())
                    return false;
            } else {
                for (int iter = 0, arr_iter = hashmap[p[iter]]; iter < p.size(); iter++, arr_iter++){
                    if (hashmap.find(p[iter]) == hashmap.end())
                        return false;
                    if (hashmap[p[iter]] != arr_iter)
                        return false;
                }
            }
        }
        return true;
    }
};