/**
693. Binary Number with Alternating Bits
    Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.
    Example :
    Input: n = 5
    Output: true
    Explanation: The binary representation of 5 is: 101
 */


class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = n & 1;
        n >>= 1;
        while (n > 0){
            int curr = n & 1;
            if (curr == prev)
                return false;
            prev = curr;
            n >>= 1;
        }
        return true;
    }
};