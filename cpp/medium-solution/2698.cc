/*
2698. Find the Punishment Number of an Integer
    Given a positive integer n, return the punishment number of n.
    The punishment number of n is defined as the sum of the squares of all integers i such that:
    1 <= i <= n
    The decimal representation of i * i can be partitioned into contiguous substrings such that the sum of the integer values of these substrings equals i.

    Example :
    Input: n = 10
    Output: 182
    Explanation: There are exactly 3 integers i in the range [1, 10] that satisfy the conditions in the statement:
    - 1 since 1 * 1 = 1
    - 9 since 9 * 9 = 81 and 81 can be partitioned into 8 and 1 with a sum equal to 8 + 1 == 9.
    - 10 since 10 * 10 = 100 and 100 can be partitioned into 10 and 0 with a sum equal to 10 + 0 == 10.
    Hence, the punishment number of 10 is 1 + 81 + 100 = 182
*/

#include <string>
using namespace std;

class Solution {
    public:
        int partition(const string& num, int target, int index = 0){
            if ( index == num.size()){
                return target == 0;
            }
            int idx = 0;
            for (int i = index; i < num.size(); i++){
                idx = idx * 10 + (num[i] - '0');
                if (idx > target)
                    break;
                if (partition(num, target - idx, i + 1)){
                    return true;
                }
            }
            return false;
        }
        int punishmentNumber(int n) {
            int total = 0;
            for (int i = 1; i <= n; i++){
                int square = i * i;
                if (partition(to_string(square), i)){
                    total += square;
                }
            }
            return total;
        }
    };