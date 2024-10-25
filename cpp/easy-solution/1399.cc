/*
1399. Count Largest Group
    You are given an integer n.
    Each number from 1 to n is grouped according to the sum of its digits.
    Return the number of groups that have the largest size.

    Example :
    Input: n = 13
    Output: 4
    Explanation: There are 9 groups in total, they are grouped according sum of its digits of numbers from 1 to 13:
    [1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9].
    There are 4 groups with largest size.
*/

#include <algorithm>
using namespace std;
class Solution {
    int sum_digit(int n){
        int res = 0;
        while(n){
            res += n % 10;
            n /= 10;
        }
        return res;
    }
public:
    int countLargestGroup(int n) {
        int freq[40] = {0};
        for (int i = 1; i <= n; i++){
            freq[sum_digit(i)]++;
        }
        sort(rbegin(freq), rend(freq));
        return count(begin(freq), end(freq), freq[0]);
    }
};