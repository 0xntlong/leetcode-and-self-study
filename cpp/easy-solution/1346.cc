/*
1346. Check If N and Its Double Exist
    Given an array arr of integers, check if there exist two indices i and j such that :
    i != j
    0 <= i, j < arr.length
    arr[i] == 2 * arr[j]
    Example:

    Input: arr = [10,2,5,3]
    Output: true
    Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]
*/

#include <vector>
using namespace std;
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int N = arr.size();
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (i != j && arr[i] == 2 * arr[j]){
                    return true;
                }
            }
        }
        return false;
    }
};