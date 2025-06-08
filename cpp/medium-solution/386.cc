/*
386. Lexicographical Numbers
    Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.
    You must write an algorithm that runs in O(n) time and uses O(1) extra space. 

    Example :
    Input: n = 13
    Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
*/

#include <vector>
using namespace std;
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        int curr = 1;
        for (int i = 0; i < n; i++){
            res[i] = curr;
            if (curr * 10 > n){
                if (curr == n) 
                    curr /= 10;
                curr++;
                while (curr % 10 == 0){
                    curr /= 10;
                }
            } else {
                curr *= 10;
            }
        }
        return res;
    }
};